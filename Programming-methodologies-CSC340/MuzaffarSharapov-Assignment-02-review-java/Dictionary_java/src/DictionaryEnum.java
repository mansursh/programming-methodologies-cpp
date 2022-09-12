import java.util.*;


//TEPOS = The Eight Part Of Speach
// POS = Part of Speech

enum DictionaryEnum {


    Alcohol("Alcohol", "noun", "“The buffer between reality and a good night, has been known to make obviously stupid ideas seem like a good sense."),
    Arrow("Arrow", "noun", "Here is one arrow: <IMG> -=>> </IMG>"),
    Book1("Book", "noun", "A set of pages."),
    Book2("Book", "noun", "A written work published in printed or electronic form."),
    Book3("Book", "verb", "To arrange for someone to have a seat on a plane."),
    Book4("Book", "verb", "To arrange something on a particular date."),
    Distinct1("Distinct", "adjective", "Familiar. Worked in Java."),
    Distinct2("Distinct", "adjective", "Unique. No duplicates. Clearly different or of a different kind."),
    Distinct3("Distinct", "adverb", "Uniquely. Written 'distinctly'."),
    Distinct4("Distinct", "noun", "A keyword in this assignment."),
    Distinct5("Distinct", "noun", "A keyword in this assignment."),
    Distinct6("Distinct", "noun", "A keyword in this assignment."),
    Distinct7("Distinct", "noun", "An advanced search option."),
    Distinct8("Distinct", "noun", "Distinct is a parameter in this assignment."),
    Empty1("", null, "PARAMETER HOW-TO,  please enter:"),
    Empty2("", null, "1. A search key -then 2. An optional part of speech -then"),
    Empty3("", null, "3. An optional 'distinct' -then 4. An optional 'reverse'"),
    Help1("!help", null, "PARAMETER HOW-TO,  please enter:"),
    Help2("!help", null, "1. A search key -then 2. An optional part of speech -then"),
    Help3("!help", null, "3. An optional 'distinct' -then 4. An optional 'reverse'"),
    Placeholder1("Placeholder", "adjective", "To be updated..."),
    Placeholder2("Placeholder", "adjective", "To be updated..."),
    Placeholder3("Placeholder", "adverb", "To be updated..."),
    Placeholder4("Placeholder", "conjunction", "To be updated..."),
    Placeholder5("Placeholder", "interjection", "To be updated..."),
    Placeholder6("Placeholder", "noun", "To be updated..."),
    Placeholder7("Placeholder", "noun", "To be updated..."),
    Placeholder8("Placeholder", "noun", "To be updated..."),
    Placeholder9("Placeholder", "preposition", "To be updated..."),
    Placeholder10("Placeholder", "pronoun", "To be updated..."),
    Placeholder11("Placeholder", "verb", "To be updated..."),
    Reverse1("Reverse", "adjective", "On back side."),
    Reverse2("Reverse", "adjective", "Opposite to usual or previous arrangement."),
    Reverse3("Reverse", "noun", "A dictionary program's parameter."),
    Reverse4("Reverse", "noun", "Change to opposite direction."),
    Reverse5("Reverse", "noun", "The opposite."),
    Reverse6("Reverse", "noun", "To be updated..."),
    Reverse7("Reverse", "noun", "To be updated..."),
    Reverse8("Reverse", "noun", "To be updated..."),
    Reverse9("Reverse", "noun", "To be updated..."),
    Reverse10("Reverse", "verb", "Change something to opposite."),
    Reverse11("Reverse", "verb", "Go back."),
    Reverse12("Reverse", "verb", "Revoke ruling."),
    Reverse13("Reverse", "verb", "To be updated..."),
    Reverse14("Reverse", "verb", "To be updated..."),
    Reverse15("Reverse", "verb", "Turn something inside out.");


    private String keyWordFromEnum;
    private String partOfSpeechFromEnum;
    private String valueDefinitionFromEnum;

    private DictionaryEnum(String keyWordFromEnum, String partOfSpeechFromEnum, String valueDefinitionFromEnum) {
        this.keyWordFromEnum = keyWordFromEnum;
        this.partOfSpeechFromEnum = partOfSpeechFromEnum;
        this.valueDefinitionFromEnum = valueDefinitionFromEnum;
    }

    public String getKeyWordFromEnum() {
        return this.keyWordFromEnum.toLowerCase();
    }

    public String getPartOfSpeechFromEnum() {
        return this.partOfSpeechFromEnum;
    }

    public String getValueDefinitionFromEnum() {
        return this.valueDefinitionFromEnum;
    }

    @Override
    public String toString() {
        if (this.partOfSpeechFromEnum == null) {
            return this.valueDefinitionFromEnum;
        } else {
            return this.keyWordFromEnum + " [" + this.partOfSpeechFromEnum + "]: " + this.valueDefinitionFromEnum;

        }
    }






    public static Boolean distinct = false;
    public static Boolean reverse = false;
    public static HashMap<String, ArrayList<DictionaryEnum>> map = new HashMap<String, ArrayList<DictionaryEnum>>();


    public static ArrayList<DictionaryEnum> toReverse(ArrayList<DictionaryEnum> dictionaryArr) {


        Collections.reverse(dictionaryArr);

        reverse = false;
        return dictionaryArr;
    }


    //method to create array for same part of speech
    public static ArrayList<DictionaryEnum> toSelectSamePartOfSpeach(ArrayList<DictionaryEnum> dictionaryArr, String partOfSpeech) {
        ArrayList<DictionaryEnum> arrListSelectedPOP = new ArrayList<DictionaryEnum>();
        if (dictionaryArr != null) {
            for (DictionaryEnum data : dictionaryArr) {
                String dataGetPartOfSpeechFromEnum = data.getPartOfSpeechFromEnum();
                if (dataGetPartOfSpeechFromEnum != null && dataGetPartOfSpeechFromEnum.equalsIgnoreCase(partOfSpeech)) {
                    arrListSelectedPOP.add(data);
                }
            }
        }
        if (arrListSelectedPOP.isEmpty()) {
            System.out.println("     <NOT FOUND> To be considered for the next release. Thank you.");
            System.out.println("     |");
            System.out.println("     |");
            System.out.println("      PARAMETER HOW-TO, please enter:");
            System.out.println("      1. A search key - then 2. An optional part of speech -then");
            System.out.println("      3. An optional 'distinct' - then 4. An optional 'reverse'");
            System.out.println("     |");
        }
        return arrListSelectedPOP;
    }

    //method to make array distinct
    public static ArrayList<DictionaryEnum> toDistinct(ArrayList<DictionaryEnum> dictionaryArr) {

        HashMap<String, DictionaryEnum> hashMapOfValueAndArrDict = new HashMap<String, DictionaryEnum>();


        for (DictionaryEnum data : dictionaryArr) {
            String valueDefinition = data.getValueDefinitionFromEnum();
            Object valueHashMap = hashMapOfValueAndArrDict.get(valueDefinition);
            if (valueHashMap == null) {
                hashMapOfValueAndArrDict.put(valueDefinition, data);
            }
        }
        ArrayList<DictionaryEnum> hashMapOfValuesToSortedArrList = new ArrayList<>(hashMapOfValueAndArrDict.values());
        if (!hashMapOfValueAndArrDict.toString().equalsIgnoreCase("reverse")) {
            Collections.sort(hashMapOfValuesToSortedArrList);
        }


//        Set<DictionaryEnum> hashSet = new HashSet<>(dictionaryArr);
//
//        ArrayList<DictionaryEnum> distinctArrListFromHashSet = new ArrayList<>();
//        dictionaryArr.clear();
//        dictionaryArr.addAll(hashSet);
//          Collections.sort(dictionaryArr);
//        HashSet<String, DictionaryEnum> hashMapOfValueAndArrDict = new HashSet<String, DictionaryEnum>();
//
//        ArrayList<DictionaryEnum> hashMapOfValuesToSortedArrList = new ArrayList<HashSet>(hashMapOfValueAndArrDict);
//        if (!hashMapOfValueAndArrDict.toString().equalsIgnoreCase("reverse")) {
//            Collections.sort(hashMapOfValuesToSortedArrList);
//        }
        //  Collections.sort(distinctArrListFromHashSet);

//        System.out.println("distinctArrListFromHashSet.toString().equalsIgnoreCase:" + distinctArrListFromHashSet.toString().equalsIgnoreCase("reverse"));
//        System.out.println("hashSet " + hashSet);
//        if (!distinctArrListFromHashSet.toString().equalsIgnoreCase("reverse")) {
//            Collections.reverse(distinctArrListFromHashSet);
//        }

        //        return dictionaryArr;
        distinct = false;

        return hashMapOfValuesToSortedArrList;
    }


    public static void main(String[] args) {

        int numberSearchInput = 0;
        boolean trueKeepLoop = true;
        String[] keyWords = {"Alcohol", "Arrow", "Book", "Distinct", "Placeholder", "Reverse"};
        System.out.println("! Loading data...");


        //loads enum data into a hashmap
        for (DictionaryEnum data : DictionaryEnum.values()) {
            String key = data.getKeyWordFromEnum();

            ArrayList<DictionaryEnum> valueDefinitionArray;

            if (map.containsKey(key)) {
                valueDefinitionArray = map.get(key);
            } else {
                valueDefinitionArray = new ArrayList<DictionaryEnum>();
            }
            valueDefinitionArray.add(data);
            map.put(key, valueDefinitionArray);

        }

        System.out.println("! Loading complete...");
        System.out.println("\n===== DICTIONARY 340 JAVA =====");

        System.out.println("----- Keywords: " + keyWords.length);
        System.out.println("----- Definitions: " + DictionaryEnum.values().length + "\n");


        while (trueKeepLoop) {
            numberSearchInput++;
            System.out.print("Search [" + numberSearchInput + "]: ");
            Scanner input = new Scanner(System.in);
            String inputNextLine = input.nextLine();
            String partOfSpeechString = null;
            String word = null;
            distinct = false;
            reverse = false;
            String[] wordFromInput = inputNextLine.split(" ");
            String[] theEightPartOfSpeech = {"adjective", "adverb", "conjunction", "interjection", "noun", "preposition", "pronoun", "verb"};

            if (wordFromInput.length > 0) {
                word = wordFromInput[0];
            }
            if (wordFromInput.length > 1 && wordFromInput[1] != null) {
                if (Arrays.asList(theEightPartOfSpeech).contains(wordFromInput[1].toLowerCase())) {
                    partOfSpeechString = wordFromInput[1];
                } else if (wordFromInput[1].toLowerCase().equalsIgnoreCase("distinct")) {
                    distinct = true;
                } else if (wordFromInput[1].toLowerCase().equalsIgnoreCase("reverse")) {
                    reverse = true;
                } else {
                    System.out.println("     |");
                    System.out.println("     <The entered 2nd wordFromInput '" + wordFromInput[1] + "' is NOT a part of speech.>");
                    System.out.println("     <The entered 2nd wordFromInput '" + wordFromInput[1] + "' is NOT 'distinct'.>");
                    System.out.println("     <The entered 2nd wordFromInput '" + wordFromInput[1] + "' is NOT 'reverse'.>");
                    System.out.println("     <The entered 2nd wordFromInput '" + wordFromInput[1] + "' was disregarded.>");
                    System.out.println("     <The 2nd wordFromInput should be a part of speech or 'distinct' or 'reverse'.>");
                    System.out.println("     |");
                }
            }
            if (wordFromInput.length > 2 && wordFromInput[2] != null) {
                if ((Arrays.asList(theEightPartOfSpeech).contains(wordFromInput[2].toLowerCase()))) {
                    partOfSpeechString = wordFromInput[2];
                } else if (wordFromInput[2].toLowerCase().equalsIgnoreCase("distinct")) {
                    distinct = true;
                } else if (wordFromInput[2].toLowerCase().equalsIgnoreCase("reverse")) {
                    System.out.println("reverse is true now2");
                    reverse = true;
                } else {
                    System.out.println("     |");
                    System.out.println("     <The entered 3rd wordFromInput '" + wordFromInput[2] + "' is NOT a part of speech.>");
                    System.out.println("     <The entered 3rd wordFromInput '" + wordFromInput[2] + "' is NOT 'distinct'.>");
                    System.out.println("     <The entered 3rd wordFromInput '" + wordFromInput[2] + "' is NOT 'reverse'.>");
                    System.out.println("     <The entered 3rd wordFromInput '" + wordFromInput[2] + "' was disregarded.>");
                    System.out.println("     <The 3rd wordFromInput should be a part of speech or 'distinct' or 'reverse'.>");
                    System.out.println("     |");
                }
            }
            if (wordFromInput.length > 3 && wordFromInput[3] != null) {
                if (wordFromInput[3].toLowerCase().equalsIgnoreCase("reverse")) {
                    System.out.println("reverse is true now");
                    reverse = true;
                } else {
                    System.out.println("     |");
                    System.out.println("     <The entered 4th wordFromInput '" + wordFromInput[3] + "' is NOT 'reverse'.>");
                    System.out.println("     <The entered 4th wordFromInput '" + wordFromInput[3] + "' was disregarded.>");
                    System.out.println("     <The 4th wordFromInput should be a part of speech or 'distinct' or 'reverse'.>");
                    System.out.println("     |");
                }
            }
            if (!inputNextLine.equalsIgnoreCase("!q")) {
                System.out.println("     |");
                ArrayList<DictionaryEnum> arrWord = map.get(word.toLowerCase());
                if (arrWord != null && distinct == true && reverse == true && partOfSpeechString != null) {
                    ArrayList<DictionaryEnum> arrSamePartSpeech = toSelectSamePartOfSpeach(arrWord, partOfSpeechString);
                    ArrayList<DictionaryEnum> arrDistinct = toDistinct(arrSamePartSpeech);
                    ArrayList<DictionaryEnum> arrReverse = toReverse(arrDistinct);

                    for (DictionaryEnum data : arrReverse) {
                        System.out.print("      " + data + "\n");
                    }

                } else if (arrWord != null && distinct == true && reverse != true && partOfSpeechString == null) {
                    ArrayList<DictionaryEnum> arrDistinct = toDistinct(arrWord);

                    for (DictionaryEnum data : arrDistinct) {
                        System.out.print("      " + data + "\n");
                    }
                } else if (arrWord != null && distinct != true && reverse == true && partOfSpeechString == null) {
                    ArrayList<DictionaryEnum> arrReverse = toReverse(arrWord);

                    for (DictionaryEnum data : arrReverse) {
                        System.out.print("      " + data + "\n");
                    }

                } else if (arrWord != null && distinct != true && reverse != true && partOfSpeechString != null) {
                    ArrayList<DictionaryEnum> arrSamePartSpeech = toSelectSamePartOfSpeach(arrWord, partOfSpeechString);

                    for (DictionaryEnum data : arrSamePartSpeech) {
                        System.out.print("      " + data + "\n");
                    }
                } else if (arrWord != null && distinct == true && reverse == true && partOfSpeechString == null) {
                    ArrayList<DictionaryEnum> arrDistinct = toDistinct(arrWord);
                    ArrayList<DictionaryEnum> arrReverse = toReverse(arrDistinct);

                    for (DictionaryEnum data : arrReverse) {
                        System.out.print("      " + data + "\n");
                    }
                } else if (arrWord != null && distinct == true && reverse != true && partOfSpeechString != null) {
                    ArrayList<DictionaryEnum> arrSamePartSpeech = toSelectSamePartOfSpeach(arrWord, partOfSpeechString);
                    ArrayList<DictionaryEnum> arrDistinct = toDistinct(arrSamePartSpeech);

                    for (DictionaryEnum data : arrDistinct) {
                        System.out.print("      " + data + "\n");
                    }
                } else if (arrWord != null && distinct != true && reverse == true && partOfSpeechString != null) {
                    ArrayList<DictionaryEnum> arrSamePartSpeech = toSelectSamePartOfSpeach(arrWord, partOfSpeechString);
                    ArrayList<DictionaryEnum> arrReverse = toReverse(arrSamePartSpeech);

                    for (DictionaryEnum data : arrReverse) {
                        System.out.print("      " + data + "\n");
                    }
                } else if (arrWord != null && distinct != true && reverse != true && partOfSpeechString == null) {
                    for (DictionaryEnum data : arrWord) {
                        System.out.print("      " + data + "\n");
                    }
                } else if (wordFromInput.length > 4) {
                    System.out.println("|\n" +
                            "     PARAMETER HOW-TO,  please enter:\n" +
                            "     1. A search key -then 2. An optional part of speech -then\n" +
                            "     3. An optional 'distinct' -then 4. An optional 'reverse'\n" +
                            "    |");
                } else {
                    System.out.println("     <NOT FOUND> To be considered for the next release. Thank you.");
                    System.out.println("     |");
                    System.out.println("     |");
                    System.out.println("      PARAMETER HOW-TO, please enter:");
                    System.out.println("      1. A search key - then 2. An optional part of speech -then");
                    System.out.println("      3. An optional 'distinct' - then 4. An optional 'reverse'");
                    System.out.println("     |");
                }
                System.out.println("     |");
            } else {
                System.out.println("-----THANK YOU-----");
                trueKeepLoop = false;
            }
        }
    }
}

