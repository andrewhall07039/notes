1. less column data
```
grep '2000013038' postOffice-log.lx-nj-ommpo01.20200117.SYB |column -ts ',' |less -S

2. awk non-greedy
echo "@article{gjn, Author =   {Grzegorz J. Nalepa}, " | awk '{ sub(/@.*,/,""); print }'

If you want to select @ and up to the first , after that, you need to specify it as @[^,]*,

That is @ followed by any number (*) of non-commas ([^,]) followed by a comma (,).

awk '{match($0, /text=([^\|]*)\|/,m); print m[1]}' yb_voice.log
