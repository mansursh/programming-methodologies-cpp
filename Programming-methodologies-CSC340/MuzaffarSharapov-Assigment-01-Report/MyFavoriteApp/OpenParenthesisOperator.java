public class OpenParenthesisOperator extends Operator {
    @Override
    public int priority() {
        int priority = 1;
        return priority;
    }

    @Override
    public Operand execute(Operand firstOperand, Operand secondOperand) {
        return null;
    }
}