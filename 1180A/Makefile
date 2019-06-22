SHELL = /bin/bash
FLAGS = -std=c++14 -Wall -Wextra -pedantic
# FLAGS = -std=c++14 -Wall -Wextra -pedantic -Wfloat-equal -Wlogical-op -Wredundant-decls -Wconversion -Wcast-qual -Wcast-align -Wuseless-cast
CXXFLAGS = $(FLAGS) -O2
target = main
rm_prefix = $(subst test-in,,$1)
make = make --no-print-directory
dl = 2

test: in_0 $(target)
	time $(make) $(addprefix test-,$(shell ls -v in*))

test-in%:
#	./$(target) < in$(call rm_prefix,$@)
	time ./$(target) < in$(call rm_prefix,$@) | ~/bin/cat-police | nl -w4 -s': ' | diff -u <(nl -w4 -s': ' out$(call rm_prefix,$@)) - | sed 's/\([0-9]\+\):\([0-9]\+\):\([0-9]\+\)/\1-\2-\3/g'; exit $${PIPESTATUS[3]}
#	./$(target) < in$(call rm_prefix,$@) | ruby -e 'e=0;f=ARGV.map {|n|n=="-" ? STDIN : open(n)};while l=f[0].gets;m=f[1].gets;if(l.to_f-m.to_f).abs>=0.000001;puts"< #{l}> #{m}";e=1;end;end;exit e' - out$(call rm_prefix,$@)

in_0 : test.txt
	make clean
	ruby -ne'BEGIN{b=[]};if$$_=~/^# /;b<<"";else b[-1]<<$$_;end;END{b.each.with_index{|f,i|File.write("#{i.odd? ? "out":"in"}_#{i/2}",f)}}'<$<

clean:
	rm -f $(target) in* out* gmon.out

debug: in_0 $(target)
	$(make) -B $(target) $(addprefix debug-,$(shell ls -v in*)) CXXFLAGS="$(FLAGS) -g"

debug-in%:
	gdb ./$(target)

profile:
	$(make) -B test CXXFLAGS="$(FLAGS) -pg -g"
	gprof ./$(target) gmon.out | less
	$(make) clean

download:
	for i in "https://judgedat.u-aizu.ac.jp/testcases/$$([[ $$1 ]]&&echo $$1 || echo $$(basename `pwd`))/"{1..$(dl)}; { echo "# in $$i"; curl $$i/in ; echo "# out $$i"; curl $$i/out; } >> test.txt

rank:
	curl -sS https://judgeapi.u-aizu.ac.jp/users/ranking/solved\?page=0\&size=1000 | jq --raw-output '.users[] | select(.id == "boxnos") | {rank: .rank, solved: .solved} | "solved: \(.solved) \(.rank)th"'
	curl -sS https://judgeapi.u-aizu.ac.jp/users/ranking/rating\?page=0\&size=1000 | jq --raw-output '.users[] | select(.id =="boxnos") | {rank: .rank, rating: .rating, diff: .diff} | "rating: \(.rating) +\(.diff) \(.rank)th"'

