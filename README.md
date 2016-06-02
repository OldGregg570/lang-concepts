# lang-concepts HW 4
Programming Language Concepts assignment number 4

# Usage

```
cd(".../path/to/project/lang-concepts/")


>> c("src/collatz").        
{ok,collatz}

>> collatz:getSequence(3).
[3,10,5,16,8,4,2,1]

>> collatz:getCount(7).
17

>> [{X, collatz:getCount(X)} || X <- [1, 2, 3, 4, 5]].
[{1,1},
 {2,2},
 {3,8},
 {4,3},
 {5,6}]

>> collatz:getCount(1111111111111111).
457


>> c("src/fibonacci").                                                    
{ok,fibonacci}

>> fibonacci:getSequence(10).
[0,1,1,2,3,5,8,13,21,34]

>> fibonacci:getNth(15).
377

>> fibonacci:getNth(1500).
8375056248993139455049166839161507580700951645259326077476024530190249793122625956172711451179970423221527641010767943444743688189586986881311526079669891181504713074057187888904564000541671421981786662930007521318154320452258888890718832980474892271737110708355492262357711279126593613602544365827073452325051001


>> c("src/factorial").                                                    
{ok,factorial}

>> factorial:getNth(12).
479001600

>> factorial:getNth(120).
6689502913449127057588118054090372586752746333138029810295671352301633557244962989366874165271984981308157637893214090552534408589408121859898481114389650005964960521256960000000000000000000000000000


>> c("src/client").
{ok,client}

>> PID = client:run().
<0.33.0>

>> client:request(PID, {area, {square, 3}}).
Square Area: 9
Server Response: 9
ok

```
