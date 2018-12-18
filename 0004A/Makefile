SHELL = /bin/bash
FLAGS = -std=c++14
#FLAGS = -std=c++11 -Wall -Wextra
CXXFLAGS = $(FLAGS) -O2
target = main
rm_prefix = $(subst test-in,,$1)
make = make --no-print-directory

test: in_0 $(target)
	time $(make) $(addprefix test-,$(shell ls -v in*))

test-in%:
#	./$(target) < in$(call rm_prefix,$@)
	time ./$(target) < in$(call rm_prefix,$@) | diff -u out$(call rm_prefix,$@) - | tr ':' '-'; exit $${PIPESTATUS[1]}
#	./$(target) < in$(call rm_prefix,$@) | ruby -e 'e=0;f=ARGV.map {|n|n=="-" ? STDIN : open(n)};while l=f[0].gets;m=f[1].gets;if(l.to_f-m.to_f).abs>=0.0001;puts"< #{l}> #{m}";e=1;end;end;exit e' - out$(call rm_prefix,$@)

in_0 : test.txt
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
	for i in "https://judgedat.u-aizu.ac.jp/testcases/$$([[ $$1 ]]&&echo $$1 || echo $$(basename `pwd`))/"{1..1}; { echo "# in $$i"; curl $$i/in ; echo "# out $$i"; curl $$i/out; } >> test.txt

rank:
	curl -sS https://judgeapi.u-aizu.ac.jp/users/ranking/solved\?page=0\&size=1000 | jq '.users[] | select(.id == "boxnos") | {rank: .rank, solved: .solved}'
	curl -sS https://judgeapi.u-aizu.ac.jp/users/ranking/rating\?page=1\&size=1000 | jq '.users[] | select(.id =="boxnos") | {rank: .rank, rating: .rating, diff: .diff}'

