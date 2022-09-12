public class DivisionOperator extends Operator {
    @Override
    public int priority() {
        return 3;
    }

    @Override
    public Operand execute(Operand firstOperand, Operand secondOperand) {
        int evalDivis = firstOperand.getValue() / secondOperand.getValue();
        Operand evalValue = new Operand(evalDivis);
        return evalValue;
    }
}
