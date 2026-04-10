# Meet in the Middle:

**Meet in the Middle:**
**`a^b -> a^(b/2)`**
**Usually where we need to do a `a^n` brute force subset finding, and apply an aggregate function while calc. subset**
**So we do `a^(n/2)` subset findings, and then hash them. And then do merging based on the earlier aggregate function.**
**Hash subsets of 1 half, and loop over other half.**