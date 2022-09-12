public class MultiplicationOperator extends Operator {
    @Override
    public int priority() {
        return 3;
    }

    @Override
    public Operand execute(Operand fristOperand, Operand secondOperand) {
        int evalMutiplication = fristOperand.getValue() * secondOperand.getValue();
        Operand evalValue = new Operand(evalMutiplication);

        return evalValue;

    }

}
