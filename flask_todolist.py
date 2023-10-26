from flask import Flask, render_template, request, redirect, url_for

app = Flask(__name__)

# Create an empty list to store the to-do items
todos = []

@app.route('/')
def index():
    return render_template('index.html', todos=todos)

@app.route('/add', methods=['POST'])
def add():
    todo = request.form.get('todo')
    todos.append(todo)
    return redirect(url_for('index'))

if __name__ == '__main__':
    app.run(debug=True)
