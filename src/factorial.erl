%%% Factorial sequence generator.

-module(factorial).
-export([getNth/1]).

%% Returns the computation N!
getNth(N) -> goodFact(N).

%% Non tail recurive factorial
naiveFact(0) -> 1;
naiveFact(N) -> N * naiveFact(N - 1).

%% Tail recursive factorial makes use of accumulator A
goodFact(N)    -> goodFact(N, 1).
goodFact(1, A) -> A;
goodFact(N, A) -> goodFact(N - 1, A * N).
