public class PowerOperator extends Operator {
    @Override
    public int priority() {
        return 4;
    }

    @Override
    public Operand execute(Operand fristOperand, Operand secondOperand) {
        int evalPower = (int) Math.pow(fristOperand.getValue(), secondOperand.getValue());
        Operand evalValue = new Operand(evalPower);
        return evalValue;
    }
}