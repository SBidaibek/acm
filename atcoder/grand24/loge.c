new 35
00:31 - O0 = when deleting a char s[i] > s[i + 1] must hold
        or the suffix must conisst of the same char
00:28 - O1 = K is also a const so it must be used in dp
00:28 - Q0 = how to solve if only 2 strings are needed
00:26 - O2 = deleteing a char from a segment of same gives the same
            result
00:08 - O3 = we can paraphrase the question as finding a string and
            a permutation
new 35
00:31 - O4 = we can put a zero at end and only s[i] > s[i + 1] must hold
00:27 - HO1 = we should choose a string and permute it and prolong it
                inserting identical chars
00:25 - O5 = something to do with a tree and its topological traversal
00:22 - I1 = count the number of trees with k nodes and char C in the root
00:17 - O6 = ans is dp[n + 1][0]
00:13 - S1 = if k[i] is number of children on level k[i] then ans is
                k[1]! * k[2]! * ... * k[depth]!

new 35
00:31 - Q1 = we need dp by level for permutations and by subtrees for chars
00:21 - S2 = d[n][k][ch], add in decresing (depth) size
00:20 - A1 = im fkn stupid its multiplication of multitplications order doesnt
            matter
00:16 - S21 = iterate in a cycle inside over the childs size
00:15 - I1 = implem S2
00:12 - Stop I1 think more
00:09 - S1 is shit
00:06 - rather it is dividing n into c colors where c is number of children
        the arrangemnt is unique based on the order of the maximal elements
        of each group
00:04 - which in its turn is just uniting with c(n + new, new)
00:03 - I2 = therefore sol is to d[n][k] and add groups with cnk
00:01 - Q2 = what is k?

new 35
00:34 - I2 is slow because of colors, lets implement anyways to see what
        happens
00:32 - shit it overcalcs, so lets do it forward, and k is
        exactly max char used
00:25 - nono lets make it backwards
00:23 - it will overcalc ((
00:21 - k is exactly max color used
00:16 - I remembered why i wanted to do it forwards, we need
        to merge the max node with others so no overcalc
        occurs
00:05 - sampling I2

new 35
00:24 - O3 is shit, it overcalcs, its not a permutation
        it will only hold in case a[i] != a[i + 1]
00:21 - O7 = p[i] for segment of consectuive a[i] == a[i + 1]
        should be sorted
00:15 - O8 = if s conists of char <= k - 1 than new chars = k
        will be last in the permutation since
        we cant connect other to them
00:14 - I3 = therefore its enough to add a bunch of ks
