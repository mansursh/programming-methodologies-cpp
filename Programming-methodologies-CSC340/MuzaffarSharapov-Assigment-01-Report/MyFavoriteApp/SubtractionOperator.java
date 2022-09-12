public class SubtractionOperator extends Operator {
    @Override
    public int priority() {
        return 2;
    }

    @Override
    public Operand execute(Operand firstOperand, Operand secondOperand) {
        int evalSubtraction = firstOperand.getValue() - secondOperand.getValue();
        Operand evalValue = new Operand(evalSubtraction);
        return evalValue;
    }
}
