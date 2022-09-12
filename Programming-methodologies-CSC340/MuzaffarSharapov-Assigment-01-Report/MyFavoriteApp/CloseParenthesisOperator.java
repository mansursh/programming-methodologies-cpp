public class CloseParenthesisOperator extends Operator {
    @Override
    public int priority() {
        return 5;
    }

    @Override
    public Operand execute(Operand firstOperand, Operand secondOperand) {
        return null;
    }
}
