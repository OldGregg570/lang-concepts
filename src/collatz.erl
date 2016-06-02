%%% Collatz sequence generator.

-module(collatz).
-export([getSequence/1]).
-export([getCount/1]).

%% Returns the collatz sequence for the specified start value
getSequence(START) -> collatz(START, []).

%% Returns the length of the collatz sequence for the specified start value
getCount(START) -> length(getSequence(START)).

% Private interface
collatz(1, _)                 -> [1];
collatz(START, [])            -> collatz(START, [START]);
collatz(START, [HEAD | TAIL]) ->
  case (START rem 2) of
    0 -> [HEAD | collatz(START div 2,   TAIL)];
    1 -> [HEAD | collatz(START * 3 + 1, TAIL)]
  end.
