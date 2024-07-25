# baseballScore

You are keeping score for a basketball game with some new rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the operation you must apply to the record, with the following rules:
+ A non-negative integer x (from 0 to 9) - record a new score of x
+ '+' - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
+ 'D' - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
+ 'C' - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.

Finally, return the sum of all scores in the record.

**For example:**
<br/>
ops = "52CD+"

+ '5' - add to the record. Record now is [5]
+ '2' - add to the record. Record now is [5,2]
+ 'C' - invalid the previous score (2). Record now is [5]
+ 'D' - Record new score that is double of previous score (5*2). Record now is [5,10]
+ '+' - Record a new score that is the sum of the previous two scores. Record now is [5,10,15]

Return the sum: 5+10+15 = 30

**For example:**

+ Test 1: cout << baseballScore("52CD+");
+ Result 1: 30
<br/>

+ Test 2: cout << baseballScore("524CD9++");
+ Result 2: 55
<br/>

+ Test 3: cout << baseballScore("5C4C2C11+D3");
+ Result 3: 11
---
