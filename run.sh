g++ $(for f in *.cpp; do echo -n $f; echo -n ' '; done;) $(for f in *.h; do echo -n $f; echo -n ' '; done;) -o main && ./main
