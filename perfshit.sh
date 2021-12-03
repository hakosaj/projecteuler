echo "Perfing and plotting the performance of $1"
sudo perf stat $1
sudo perf record -g $1
sudo perf script | c++filt | gprof2dot -f perf | dot -Tpng -o $1.png
feh $1.png
