# Simple summary:


 <span style="font-size: 22.0;">
     # **mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());**

 </span> <span style="font-size: 22.0;">
     # **int randint(int l, int r) {**

 </span> <span style="font-size: 22.0;">
     #     **return rng() % (r - l + 1) + l;**

 </span> <span style="font-size: 22.0;">
     # **}**

 </span> <span style="font-size: 25.0;">
     # **shuffle(container.begin(), container.end(), rng);**
 </span>