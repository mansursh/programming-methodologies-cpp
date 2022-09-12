import java.util.HashMap;

public abstract class Operator {

  private static HashMap<String, Operator> operators;
  static {
    operators = new HashMap<>();
    operators.put("+", new AdditionOperator());
    operators.put("-", new SubtractionOperator());
    operators.put("*", new MultiplicationOperator());
    operators.put("/", new DivisionOperator());
    operators.put("^", new PowerOperator());
    operators.put("(", new OpenParenthesisOperator());
    operators.put(")", new CloseParenthesisOperator());
  }

  public abstract int priority();

  public abstract Operand execute(Operand fristOperand, Operand secondOperand);

  public static boolean check(String token) {
    if (operators.containsKey(token)) {
      return true;
    }
    return false;
  }

  public static Operator getOperator(String token) {
    if (check(token)) {
      return operators.get(token);
    }
    return null;
  }

  public static String operatorsKeySetToString() {
    String keyStringCompbine = "";
    for (String key : operators.keySet()) {
      keyStringCompbine += key;
    }
    return keyStringCompbine;
  }
}