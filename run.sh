g++ $(for f in *.cpp; do echo -n $f; echo -n ' '; done;) $(for f in *.h; do echo -n $f; echo -n ' '; done;) -DPLATFORM_UNIX -o main && ./main
#for debug and "better keys" run
#g++ $(for f in *.cpp; do echo -n $f; echo -n ' '; done;) $(for f in *.h; do echo -n $f; echo -n ' '; done;) -DPLATFORM_UNIX -Dbetterkeys -o main && ./main