# Mobius Inversion / PIE DP

> **(Combinatorics + Number Theory)**

## Equivalent DP Trick

> **Note:** Try all the 3 problems in the Blog, couldn’t do any of them on my own, which is sooo bad.

**Somehow, for all three problems, we did it over gcd!**

<https://codeforces.com/blog/entry/83757>

Most of the problems presented in this article will probably have a solution using Möbius inversion or some combinatorial approach (usually the inclusion-exclusion principle). It can probably be proven that this trick is equivalent to the inclusion-exclusion principle, but I still believe that it is worth knowing, since it is very intuitive and simple.

*It is based on, roughly speaking, overcounting and compensating for it.*

![5671C2DE-ADB6-4AF4-A520-5F2FFA325C3E](images/5671C2DE-ADB6-4AF4-A520-5F2FFA325C3E.png)

## Gemini Summary on PIE DP Trick

![91E0D2DB-11E8-440E-9665-82C879DB37BC](images/91E0D2DB-11E8-440E-9665-82C879DB37BC.png)

![CBB7BF5C-D982-4936-BD4F-908F245584B1](images/CBB7BF5C-D982-4936-BD4F-908F245584B1.png)

![E81089C7-5E71-4755-B6AB-845C26F87744](images/E81089C7-5E71-4755-B6AB-845C26F87744.png)

![5175F93C-5118-49D0-8755-96BBB4291DD1](images/5175F93C-5118-49D0-8755-96BBB4291DD1.png)

![4CAB59C0-FD8A-4ABE-A644-BD40286CD13F](images/4CAB59C0-FD8A-4ABE-A644-BD40286CD13F.png)

![8B4BCBEC-2306-4DDC-B0A6-901CE04D5454](images/8B4BCBEC-2306-4DDC-B0A6-901CE04D5454.png)

## How Colin sees it

![32B84C72-A78A-4EFD-A81E-F9D17CEB2BAA](images/32B84C72-A78A-4EFD-A81E-F9D17CEB2BAA.png)

![DAC6BB3B-1ECF-4EB5-9C7E-411A291072EC](images/DAC6BB3B-1ECF-4EB5-9C7E-411A291072EC.png)

![20ED41DA-C7C3-4B75-A280-E259992F4235](images/20ED41DA-C7C3-4B75-A280-E259992F4235.png)

## Pure Mobius maybe

**I think pure Mobius is faster `O(n)` whereas the PIE DP is slower `O(3^n)` or `O(n log n)`, but the PIE DP also calculates more stuff.**

## Other resources (Blog, Video & Kactl)

<https://codeforces.com/blog/entry/53925>

<https://www.youtube.com/watch?v=51RQaeEiVvQ>

![0048314F-59EE-4CFC-8108-7E10955E67A0](images/0048314F-59EE-4CFC-8108-7E10955E67A0.png)

## Too proud of my solution to this problem

> (Uses PIE DP + 3^n bitmask traversal trick + only need unique prime factors)

<https://codeforces.com/problemset/problem/2037/G>

**Nice practice problem:**

<https://codeforces.com/problemset/problem/1559/E>
