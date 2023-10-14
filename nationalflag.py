import turtle

creator_name = "Sufiyan Khan"  

def draw_rectangle(fill_color, width, height):
    pen.begin_fill()
    pen.fillcolor(fill_color)
    for _ in range(2):
        pen.forward(width)
        pen.right(90)
        pen.forward(height)
        pen.right(90)
    pen.end_fill()

pen = turtle.Turtle()
turtle.screensize(1100, 1100)
turtle.title("National Flag Of India")

# Display the creator's name to the left of the flag
pen.up()
pen.goto(-500, 0)
pen.write(f"Created by {creator_name}", align="left", font=("Arial", 16, "normal"))

pen.up()
pen.pensize(4)
pen.goto(0, -300)
pen.down()
pen.goto(0, 400)
draw_rectangle("orange", 400, 100)

pen.goto(0, 300)
pen.forward(200)
pen.color("blue")
pen.circle(-50)
pen.setheading(270)
pen.forward(50)
pen.setheading(0)

for _ in range(24):
    pen.forward(45)
    pen.bk(45)
    pen.left(15)

pen.setheading(90)
pen.forward(50)
pen.setheading(0)

pen.color("black")
pen.forward(200)
pen.right(90)
pen.forward(100)
pen.right(90)
pen.forward(400)
pen.right(90)
pen.forward(100)
pen.right(90)
pen.goto(0, 200)
draw_rectangle("green", 400, 100)

turtle.done()
