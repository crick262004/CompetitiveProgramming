# EV / LOE / Contribution


 <span style="font-size: 27.0;">
     **[https://codeforces.com/blog/entry/62690](https://codeforces.com/blog/entry/62690)**
 </span> <span style="font-size: 27.0;">
     
**(try the contribution technique problems: 4 & 6)**
 </span>
 <span style="font-size: 33.0;">
     
**There is often a recursive, dp way of solving Probability problems. (refer to DP Folder)**

 </span>


![FC666E27-A073-4F64-8419-902882B16F49](images/FC666E27-A073-4F64-8419-902882B16F49.png) <span style="font-size: 33.0;">
     

**Because of LoE:
EV(no. of Ace, drawing out 10 cards, w replacement)
 = 
EV(no. of Ace, drawing out 10 cards, w/o replacement) 
= 
EV(no. of Ace, drawing out 10 cards all at once) 
= 
10 * E(no. of Ace, in 1 or first draw)

P(1st draw is Ace) = P(ith draw is Ace) 
Look at it by shuffling the deck, then ith draw is the ith index card in the shuffled deck.**
 </span>
![E267CD68-241C-44E2-A8F4-9128031F3D84](images/E267CD68-241C-44E2-A8F4-9128031F3D84.png)
 <span style="font-size: 33.0;">
     

**Understand that these 2 POV of problems are equivalent.**

 </span>![C1B5C5F4-5AC8-44E8-AC9A-FACBAA5F8D7C](images/C1B5C5F4-5AC8-44E8-AC9A-FACBAA5F8D7C.png)
Contribution technique is more visible, when doing it from Second Problem POV.

 <span style="font-size: 33.0;">
     **Contribution technique is when you need to calc. a final answer, but then change perspective to what is each component’s contribution to the final answer.
It is closely connected to Linearity of Expectation.**
 </span>