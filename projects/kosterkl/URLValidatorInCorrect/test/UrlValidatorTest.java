import junit.framework.TestCase;
import java.util.ArrayList;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing
       System.out.println("MANUAL TESTING:");
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       System.out.println("http://www.google.com - Expected: true  Actual: " + urlVal.isValid("http://www.google.com"));    //True
       System.out.println("http://www.google.com:80 - Expected: true  Actual: " + urlVal.isValid("http://www.google.com:80"));    //True
       System.out.println("http://www.facebook.com - Expected: true  Actual: " + urlVal.isValid("http://www.facebook.com"));    //True
       System.out.println("http://15.6349.12 - Expected: false  Actual: " + urlVal.isValid("http://15.6349.12"));    //False
       System.out.println("http/www.asdfasdfasdf.com - Expected: false  Actual: " + urlVal.isValid("http/www.asdfasdfasdf.com"));    //False       
   }
   
   
   //Scheme
   public void testYourFirstPartition()
   {
       System.out.println("\nFIRST PARTITIONING TEST - SCHEME:");
     //You can use this function to implement your First Partition testing       
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       System.out.println("http:// - Expected: true  Actual: " + urlVal.isValid("http://"));    //True
       System.out.println(":// - Expected: false  Actual: " + urlVal.isValid("://"));    //False

   }
   
   //Authority
   public void testYourSecondPartition(){
         //You can use this function to implement your Third Partition testing    
       System.out.println("\nSECOND PARTITIONING TEST - AUTHORITY:");
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       System.out.println("www.google.com - Expected: true  Actual: " + urlVal.isValid("www.google.com"));    //True
       System.out.println("aaa - Expected: false  Actual: " + urlVal.isValid("aaa"));    //False
 }
   
   
 //Port
   public void testYourThirdPartition()
   {
     //You can use this function to implement your First Partition testing      
	   System.out.println("\nTHIRD PARTITIONING TEST - PORT:");
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       System.out.println(":80 - Expected: true  Actual: " + urlVal.isValid(":80"));    //True
       System.out.println(":65636 - Expected: false  Actual: " + urlVal.isValid(":65636"));    //False

   }
   
   
   //PathOptions
   public void testYourFourthPartition(){
         //You can use this function to implement your Third Partition testing 
	   System.out.println("\nFOURTH PARTITIONING TEST - PATHOPTIONS:");
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       System.out.println("/test1 - Expected: true  Actual: " + urlVal.isValid("/test1"));    //True
       System.out.println("/# - Expected: false  Actual: " + urlVal.isValid("/#"));    //False
 }
  
   
   public void testIsValid()
   {
	   System.out.println("\nUNIT TEST:");
       //You can use this function for programming based testing
       //This code heavily influenced by testIsValid() in URLValidatorCorrect code :)
	   boolean finalVal = false;
	   ArrayList<String> correct = new ArrayList<String>();
	   ArrayList<String> notCorrect = new ArrayList<String>();
	   
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       int testCase = 2;
       int intRes = 0;
       int schemeLength = testUrlScheme.length;
       int testItr = testPartsIndex[0];
       int tPartsLength = testPartsIndex.length;
       
       do 
       {
    	   StringBuilder buffT = new StringBuilder();
    	   int itr = 0;
    	   
    	   for (int i = 4; i > 0; i--) 
    	   {
    		   if (testPartsIndex[i] == testCase) 
    		   {
    			   testPartsIndex[i - 1]++;
    			   testPartsIndex[i] = intRes;
    		   }
    	   }
    	   
    	   while (itr < tPartsLength) 
    	   {
    		   buffT.append(testUrlPartsOptions[itr][testPartsIndex[itr]]);
    		   itr++;
    	   }
    	   
    	   testPartsIndex[4]++;
    	   
    	   finalVal = urlVal.isValid(buffT.toString());
    	   
    	   if (finalVal) 
    	   {
    		   correct.add(buffT.toString());
    	   } 
    	   else 
    	   {
    		   notCorrect.add(buffT.toString());
    	   }
    	   
    	   testItr++;
    	   
       } while (testItr < schemeLength);
       
       int printCorrectItr = 0;
       int printInCorrectItr = 0;
       
       System.out.println("\nCorrect URL's:");
       
       
       while (printCorrectItr < correct.size()) 
       {
    	   System.out.println(correct.get(printCorrectItr));
    	   printCorrectItr++;
       }
       
       System.out.println("\nIncorrect URL's:");
       
       while (printInCorrectItr < notCorrect.size()) 
       {
    	   System.out.println(notCorrect.get(printInCorrectItr));
    	   printInCorrectItr++;
       }  
       
   }
   
   /*
   public void main(String[] argv)
   {
       UrlValidatorTest urlTest = new UrlValidatorTest("test");
       //System.out.println("MANUAL TESTING:");
       urlTest.testManualTest();
       
       //System.out.println("INPUT PARTITIONING:");
       urlTest.testYourFirstPartition();
       urlTest.testYourSecondPartition();
       urlTest.testYourThirdPartition();
       urlTest.testYourFourthPartition();
       
       System.out.println("UNIT TEST:");
       urlTest.testIsValid();
   }
   */
    

//-------------------- Test data for creating a composite URL
/**
 * The data given below approximates the 4 parts of a URL
 * <scheme>://<authority><path>?<query> except that the port number
 * is broken out of authority to increase the number of permutations.
 * A complete URL is composed of a scheme+authority+port+path+query,
 * all of which must be individually valid for the entire URL to be considered
 * valid.
 */
   String[] testUrlScheme = {"http://", 
           "ftp://", 
           "h3t://", 
           "3ht://", 
           "http:/", 
           "http:", 
           "http/", 
           "://", 
           ""
          };

String[] testUrlAuthority = {"www.google.com",
              "go.com", 
              "go.au", 
              "0.0.0.0", 
              "255.255.255.255", 
              "256.256.256.256", 
              "255.com", 
              "1.2.3.4.5", 
              "1.2.3.4.", 
              "1.2.3", 
              ".1.2.3.4", 
              "go.a", 
              "go.a1a", 
              "go.1aa", 
              "aaa.", 
              ".aaa",
              "aaa",
               ""
             };

String[] testUrlPort = {":80",
         ":65535",
         ":0",
         ":-1",
         ":65636",
         ":65a",
         ""
        };

String[] testUrlPathOptions = {"/test1",
                "/t123",
                "/$23",
                "/..",
                "/../", 
                "/test1/",
                "/#",
                "/test1/file",
                "/t123/file",
                "/$23/file", 
                "/../file",
                "/..//file",
                "/test1//file",
                "/#/file",
                 ""
               };

String[] testUrlQuery = {"?action=view",
          "?action=edit&mode=up",
          ""
         };

String[][] testUrlPartsOptions = {testUrlScheme, testUrlAuthority, testUrlPort, testUrlPathOptions, testUrlQuery};
int[] testPartsIndex = {0, 0, 0, 0, 0};

}