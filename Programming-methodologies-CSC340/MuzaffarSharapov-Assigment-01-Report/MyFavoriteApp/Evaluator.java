import java.util.*;

public class Evaluator {
  private Stack<Operand> operandStack;
  private Stack<Operator> operatorStack;
  private StringTokenizer tokenizer;
  private static String DELIMITERS = "+-*^/() ";
  String token;

  public Evaluator() {
    operandStack = new Stack<>();
    operatorStack = new Stack<>();
  }

  public int eval(String expression) {
    operandStack.clear();
    ;
    operatorStack.clear();
    int poppedStackOperandValue = 0;

    this.tokenizer = new StringTokenizer(expression, DELIMITERS, true);

    while (this.tokenizer.hasMoreTokens()) {
      if (!(token = this.tokenizer.nextToken().trim()).equals("")) {
        if (Operand.check(token)) {
          operandStack.push(new Operand(token));
        } else {
          if (!Operator.check(token)) {
            System.out.println("*****invalid token******");
            System.exit(1);
          }
          Operator getTokenOperator = Operator.getOperator(token);

          while (!operatorStack.isEmpty() && operatorStack.peek().priority() >= getTokenOperator.priority()) {
            if (operatorStack.peek().equals("(")) {
              int openParenthExpressIndex = expression.indexOf("(");
              int closeParenthExpressIndex = expression.indexOf(")");

              String closeParenthExpressSubstring = expression.substring(closeParenthExpressIndex + 1);

              String parentheses = expression.substring(openParenthExpressIndex + 1, closeParenthExpressIndex);
              int evaluatedParenthesesIndex = eval(parentheses);

              expression = Integer.toString(evaluatedParenthesesIndex) + closeParenthExpressSubstring;
              System.out.println(expression);
            } else {
              Operator poppedStackOperator = operatorStack.pop();
              Operand secondOperand = operandStack.pop();
              Operand firstOperand = operandStack.pop();
              operandStack.push(poppedStackOperator.execute(firstOperand, secondOperand));
            }
          }

          operatorStack.push(getTokenOperator);
        }
      }
    }

    evaluateTopStack(operatorStack.peek());
    Operand poppedStackOperand = operandStack.pop();
    poppedStackOperandValue = poppedStackOperand.getValue();

    return poppedStackOperandValue;
  }

  public void evaluateTopStack(Operator operator) {
    while (operatorStack.size() > 0) {
      Operator currentOperator = operatorStack.pop();
      Operand secondOperand = operandStack.pop();
      Operand firstOperand = operandStack.pop();
      operandStack.push(currentOperator.execute(firstOperand, secondOperand));
    }

  }
}