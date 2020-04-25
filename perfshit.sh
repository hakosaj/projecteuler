echo "Perfing and plotting the performance of $1"
perf stat $1
perf record -g $1
perf script | c++filt | gprof2dot -f perf | dot -Tpng -o $1.png
feh $1.png