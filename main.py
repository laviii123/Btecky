from turtle import Turtle, Screen
from paddle import Paddle
from ball import Ball
import time 



screen = Screen()
screen.setup(900, 600)
screen.bgcolor("black")
screen.title("This is Harsh's Ping-Pong Game")
screen.tracer(0)

l_paddle = Paddle((-410,0))
r_paddle = Paddle((410,0))
ball = Ball()




screen.listen()
screen.onkey(r_paddle.go_up, "Up")
screen.onkey(r_paddle.go_down, "Down")

screen.onkey(l_paddle.go_up, "w")
screen.onkey(l_paddle.go_down, "s")

game_is_on = True
while game_is_on:
    time.sleep(0.1)
    ball.move()
    screen.update()

    ## Detect the colision with wall
    if ball.ycor() > 280 or ball.ycor() < -280:
        ball.bounce_y()

    ## Detect the colision with paddle
    if ball.distance(r_paddle) < 50 and ball.xcor() > 390 or ball.distance(l_paddle) < 50 and ball.xcor() > -390:
        ball.bounce_x()

    ## Detect R paddle misses
    if ball.xcor() > 420:
        ball.reset_position()   

    ## Detect L paddle misses
    if ball.xcor() < -420:
        ball.reset_position()   












screen.exitonclick()
