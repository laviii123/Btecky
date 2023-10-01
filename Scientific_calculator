import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ScientificCalculator extends JFrame {
    private JTextField displayField;
    private StringBuilder inputBuffer;

    public ScientificCalculator() {
        setTitle("Scientific Calculator");
        setSize(400, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        inputBuffer = new StringBuilder();
        displayField = new JTextField();
        displayField.setEditable(false);
        displayField.setHorizontalAlignment(JTextField.RIGHT);
        displayField.setFont(new Font("Arial", Font.PLAIN, 24));

        add(displayField, BorderLayout.NORTH);
        add(createButtonPanel(), BorderLayout.CENTER);
    }

    private JPanel createButtonPanel() {
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(5, 4, 5, 5));

        String[] buttonLabels = {
                "7", "8", "9", "/",
                "4", "5", "6", "*",
                "1", "2", "3", "-",
                "0", ".", "=", "+",
                "C", "sqrt", "pow", "sin"
        };

        for (String label : buttonLabels) {
            JButton button = new JButton(label);
            button.addActionListener(new ButtonClickListener());
            buttonPanel.add(button);
        }

        return buttonPanel;
    }

    private class ButtonClickListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            JButton source = (JButton) e.getSource();
            String command = source.getText();

            switch (command) {
                case "=":
                    evaluateExpression();
                    break;
                case "C":
                    clearInput();
                    break;
                case "sqrt":
                    calculateSquareRoot();
                    break;
                case "pow":
                    inputBuffer.append("^");
                    break;
                case "sin":
                    calculateSin();
                    break;
                default:
                    inputBuffer.append(command);
                    break;
            }

            updateDisplay();
        }

        private void evaluateExpression() {
            try {
                String expression = inputBuffer.toString();
                double result = evaluate(expression);
                clearInput();
                inputBuffer.append(result);
            } catch (Exception ex) {
                clearInput();
                inputBuffer.append("Error");
            }
        }

        private double evaluate(String expression) {
            // Use a library or write a parser to evaluate the mathematical expression
            // For simplicity, we'll just use the built-in JavaScript engine
            // Note: Using JavaScript engine for evaluation is not recommended for production code
            return (double) new ScriptEngineManager().getEngineByName("JavaScript").eval(expression);
        }

        private void clearInput() {
            inputBuffer.setLength(0);
        }

        private void calculateSquareRoot() {
            try {
                double operand = Double.parseDouble(inputBuffer.toString());
                clearInput();
                inputBuffer.append(Math.sqrt(operand));
            } catch (NumberFormatException ignored) {
                clearInput();
                inputBuffer.append("Error");
            }
        }

        private void calculateSin() {
            try {
                double angle = Math.toRadians(Double.parseDouble(inputBuffer.toString()));
                clearInput();
                inputBuffer.append(Math.sin(angle));
            } catch (NumberFormatException ignored) {
                clearInput();
                inputBuffer.append("Error");
            }
        }

        private void updateDisplay() {
            displayField.setText(inputBuffer.toString());
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            ScientificCalculator calculator = new ScientificCalculator();
            calculator.setVisible(true);
        });
    }
}
