# EV / LOE / Contribution

[https://codeforces.com/blog/entry/62690](https://codeforces.com/blog/entry/62690)
*(Try the contribution technique problems: 4 & 6)*

> **Note:** There is often a recursive, DP way of solving Probability problems. (Refer to the DP Folder).

![FC666E27-A073-4F64-8419-902882B16F49](images/FC666E27-A073-4F64-8419-902882B16F49.png) 

### Linearity of Expectation (LoE)

Because of LoE:
$EV(\text{no. of Ace, drawing out 10 cards, w/ replacement})$
$=$ $EV(\text{no. of Ace, drawing out 10 cards, w/o replacement})$
$=$ $EV(\text{no. of Ace, drawing out 10 cards all at once})$
$=$ $10 \times EV(\text{no. of Ace, in 1st draw})$

$P(\text{1st draw is Ace}) = P(\text{i-th draw is Ace})$

Look at it by shuffling the deck, then the i-th draw is the i-th index card in the shuffled deck.

![E267CD68-241C-44E2-A8F4-9128031F3D84](images/E267CD68-241C-44E2-A8F4-9128031F3D84.png)

**Understand that these 2 POV of problems are equivalent.**

![C1B5C5F4-5AC8-44E8-AC9A-FACBAA5F8D7C](images/C1B5C5F4-5AC8-44E8-AC9A-FACBAA5F8D7C.png)

### Contribution Technique

Contribution technique is more visible when doing it from the Second Problem POV.

> **Contribution technique** is when you need to calculate a final answer, but then change perspective to what is each component’s contribution to the final answer. It is closely connected to Linearity of Expectation.
