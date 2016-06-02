-module(geometry).
-export([area/1]).
-export([loop/0]).

area(SHAPE) -> calcArea(SHAPE).

calcArea({square, SIDE})             -> SIDE * SIDE;
calcArea({rectangle, WIDTH, HEIGHT}) -> WIDTH * HEIGHT;
calcArea({circle, RADIUS})           -> math:pi() * RADIUS * RADIUS.

loop() ->
  receive
    % Square Area
    {FROM, {area, {square, SIDE}}} when SIDE < 0 ->
      MSG = "Invalid length parameter: ~p~n",
      io:format(MSG, [SIDE]),
      FROM ! { self(), MSG },
      loop();

    {FROM, {area, {square, SIDE}}} ->
      AREA = calcArea({square, SIDE}),
      io:format("Square Area: ~p~n", [AREA]),
      FROM ! { self(), AREA },
      loop();

    % Rectangle Area
    {FROM, {area, {rectangle, WIDTH, HEIGHT}}} when WIDTH < 0 ->
      MSG = "Invalid width parameter: ~p~n",
      io:format(MSG, [WIDTH]),
      FROM ! { self(), MSG },
      loop();

    {FROM, {area, {rectangle, WIDTH, HEIGHT}}} when HEIGHT < 0 ->
      MSG = "Invalid height parameter: ~p~n",
      io:format(MSG, [HEIGHT]),
      FROM ! { self(), MSG },
      loop();

    {FROM, {area, {rectangle, WIDTH, HEIGHT}}} ->
      AREA = calcArea({rectangle, WIDTH, HEIGHT}),
      io:format("Rectangle Area: ~p~n", [AREA]),
      FROM ! { self(), AREA },
      loop();

    % Circle Area
    {FROM, {area, {circle, RADIUS}}} when RADIUS < 0 ->
      MSG = "Invalid radius parameter: ~p~n",
      io:format(MSG, [RADIUS]),
      FROM ! { self(), MSG },
      loop();

    {FROM, {area, {circle, RADIUS}}} ->
      AREA = calcArea({circle, RADIUS}),
      io:format("Circle Area: ~p~n", [AREA]),
      FROM ! { self(), AREA },
      loop();

    % Restart
    {FROM, {restart}} ->
      PID = spawn(geometry, loop, []),
      io:format("New PID: ~p~n", [PID]),
      FROM ! { nil, PID };

    % Unhandled requests
    {FROM, _} ->
      MSG = "Error: Unsupported geometry/calculation",
      io:format(MSG ++ "~n"),
      FROM ! { self(), MSG },
      loop()
  end.

%%S = spawn(geometry, loop, []).
%%S ! {self(), {area, {square, 3}}}.
