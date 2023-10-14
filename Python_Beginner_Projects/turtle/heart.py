# Import turtle package
import turtle

# Creating a turtle object(pen)
pen = turtle.Turtle()


# Defining a method to draw curve
def curve():
    for i in range(200):
        # Defining step by step curve motion
        pen.right(1)
        pen.forward(1)


# Defining method to draw a full heart
def heart():
    # Set the fill color to red
    pen.fillcolor('red')

    # Start filling the color
    pen.begin_fill()

    # Draw the left line
    pen.left(140)
    pen.forward(113)

    # Draw the left curve
    curve()
    pen.left(120)

    # Draw the right curve
    curve()

    # Draw the right line
    pen.forward(112)

    # Ending the filling of the color
    pen.end_fill()


# Draw a heart
heart()

# To hide turtle
pen.ht()
