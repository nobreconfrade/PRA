//gcc -Wall -I/usr/include labirinto.c labirinto_teste.c -L/usrlib -lcunit -o wow

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
//#include "CUnit/Automated.h"
//#include "CUnit/Console.h"

#include "labirinto.h"

#include <stdio.h>  // for printf

/* Test Suite setup and cleanup functions: */

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/************* Test case functions ****************/

void test_case_sample(void)
{
/**
   CU_ASSERT(CU_TRUE);
   CU_ASSERT_NOT_EQUAL(2, -1);
   CU_ASSERT_STRING_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #2");

   CU_ASSERT(CU_FALSE);
   CU_ASSERT_EQUAL(2, 3);
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_EQUAL("string #1", "string #2");
*/
}

void verificar_labirinto__vazio_test(void) {
  CU_ASSERT_EQUAL( 0, -1);

}

void ler_arquivo_labirinto_test(void) {
  CU_ASSERT_EQUAL( 0, -1);

}


/**
* Funcao com o MOCK que ira falhar
*/
void mock_test(void) {
  CU_ASSERT_EQUAL( 0, -1);
}

/************* Test Runner Code goes here **************/

int main ( void )
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite( "max_test_suite", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* ADICIONA OS TESTES */
   if ( (NULL == CU_add_test(pSuite, "esta vazio", verificar_labirinto__vazio_test)) ||
	(NULL == CU_add_test(pSuite, "leu arquivo", ler_arquivo_labirinto_test)) ||
	/* AQUI DEFINE O MOCK */ 
	(NULL == CU_add_test(pSuite, "tem saida", mock_test)) ||        
	(NULL == CU_add_test(pSuite, "na entrada", mock_test)) ||
	(NULL == CU_add_test(pSuite, "anda para frente", mock_test)) ||
	(NULL == CU_add_test(pSuite, "anda para esquerda", mock_test)) ||
	(NULL == CU_add_test(pSuite, "anda para direita", mock_test)) ||
	(NULL == CU_add_test(pSuite, "anda para traz", mock_test)) ||
	(NULL == CU_add_test(pSuite, "come", mock_test)) ||
	(NULL == CU_add_test(pSuite, "saiu", mock_test)) ||
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   // Run all tests using the basic interface
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   printf("\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n\n");
/*
   // Run all tests using the automated interface
   CU_automated_run_tests();
   CU_list_tests_to_file();

   // Run all tests using the console interface
   CU_console_run_tests();
*/
   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}
