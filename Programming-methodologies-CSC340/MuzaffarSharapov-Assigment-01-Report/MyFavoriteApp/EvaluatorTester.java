
public class EvaluatorTester {
  private static int[] arrayCorrectAnswerTest = { 3, 6, -6, 8, 8, 9 };
  private static int index = 0;
  private static final String[] stringArgs = { "1+1", "7 - 1", "1-7", "2^3", "(1+1)^2+4", "3^2"

  };

  public static void main(String[] args) {
    Evaluator evaluator = new Evaluator();
    String[] test = stringArgs;

    for (String arg : test) {

      System.out.format("%s = %d\n", arg, evaluator.eval(arg));
      // System.out.println(evaluator.eval(arg) );
      int correctAns = arrayCorrectAnswerTest[index];
      int calculatedValue = evaluator.eval(arg);
      if (correctAns == calculatedValue) {
        System.out.println("Success! Passed the Test. Calculation was correct " + correctAns);
      } else {
        System.out.println("Error! Failed the Test. Calculation was not correct. Value:" + calculatedValue
            + " is NOT correct. Correct value must be " + correctAns);
      }

      index++;
    }

  }
}
