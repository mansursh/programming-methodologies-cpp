public class AdditionOperator extends Operator {
    @Override
    public int priority() {
        return 2;
    }

    @Override
    public Operand execute(Operand firstOperand, Operand secondOperand) {
        int evalAddition = firstOperand.getValue() + secondOperand.getValue();
        Operand evalValue = new Operand(evalAddition);
        return evalValue;
    }
}
