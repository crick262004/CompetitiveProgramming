# Recursive functions:

 <span style="font-size: 33.0;">
     # **[https://atcoder.jp/contests/abc350/tasks/abc350_f](https://atcoder.jp/contests/abc350/tasks/abc350_f)**
 </span> <span style="font-size: 33.0;">
     
**Idea : Just prove you need to do something simple at the outer layer, and abstract away what happens inside a complex part. And do a new recursive call over the internal complex part.**

 </span> <span style="font-size: 33.0;">
     # **As long as the internal part is always a subarray of the outer part, the recursion will work. No matter how complex the recursive function is.
SO** 

 </span> <span style="font-size: 33.0;">
     # **OUTER LAYER : Process all the indexes you can, and think are trivial. And then call recursive fn on the internal part.**
 </span>