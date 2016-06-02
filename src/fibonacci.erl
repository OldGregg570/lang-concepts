%%% Fibonacci sequence generator.

-module(fibonacci).
-export([getSequence/1]).
-export([getNth/1]).

%% Return a list of fibonacci numbers up to the Nth number
getSequence(N) -> goodFib(N, 0, 1, []).

%% Returns the value of the Nth fibonacci number
getNth(N) -> last(goodFib(N, 0, 1, [])).

%% Tail Recursive Fibonacci
goodFib(0, _, _, FIBS)          -> lists:reverse(FIBS);
goodFib(N, CURRENT, NEXT, FIBS) ->
    goodFib(N - 1, NEXT, CURRENT + NEXT, [CURRENT | FIBS]).

%% Naive Fibonacci
naiveFib(0, _, _, FIBS)          -> FIBS;
naiveFib(N, CURRENT, NEXT, FIBS) ->
    naiveFib(N - 1, NEXT, CURRENT + NEXT, FIBS ++ [CURRENT]).

%% Return the last element of a list by reversing it and returning the head
last(LIST) -> head(lists:reverse(LIST)).

head([H|T]) -> H.

%% Return the last element of a list by removing the head element until [H|[]] is matched
lastRecursive([])     -> nil;
lastRecursive([H|[]]) -> H;
lastRecursive([_|T])  -> lastRecursive(T).
