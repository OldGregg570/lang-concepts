%%% Client for geometry server

-module(client).
-export([run/0]).
-export([request/2]).
-import(geometry, [loop/0]).

%% Start the geometry server and return the resulting PID
run() ->
  PID = spawn(geometry, loop, []),
  PID.

%% Make a requst to the server and handle the response by printing it
request(PID, REQ) ->
  PID ! {self(), REQ},
  receive
    {_, MSG} ->
      io:format("Server Response: ~p~n", [MSG])
  end.
