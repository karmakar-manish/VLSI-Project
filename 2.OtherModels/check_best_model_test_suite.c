#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include "./include/k2c_include.h" 
#include "check_best_model.h" 
// #include "./include/k2c_activations.h"

float maxabs(k2c_tensor *tensor1, k2c_tensor *tensor2);
struct timeval GetTimeStamp(); 
 
float test1_fc1_input_input_array[16] = {
+3.34285233e-01f,+1.00432552e-01f,-2.10414681e-01f,-1.32963324e+00f,-1.32665389e+00f,
+1.34194846e+00f,+8.17088565e-01f,+4.69958631e-01f,+8.05792230e-01f,+9.37310738e-01f,
+3.81071832e-01f,-1.62517314e+00f,+7.28721073e-01f,+1.48329407e+00f,+1.11269050e+00f,
-4.49000081e-01f,}; 
// k2c_tensor test1_fc1_input_input = {&test1_fc1_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; // need
k2c_tensor test1_fc1_input_input;



float keras_softmax_test1_array[5] = {
+2.74044544e-01f,+2.95815498e-01f,+1.04380354e-01f,+1.58222079e-01f,+1.67537495e-01f,
}; 
// k2c_tensor keras_softmax_test1 = {&keras_softmax_test1_array[0],1,5,{5,1,1,1,1}}; // need
k2c_tensor keras_softmax_test1;


float c_softmax_test1_array[5] = {0}; 
// k2c_tensor c_softmax_test1 = {&c_softmax_test1_array[0],1,5,{5,1,1,1,1}}; // need
k2c_tensor c_softmax_test1;




// float test2_fc1_input_input_array[16] = {
// -7.82538983e-01f,+4.90944002e-01f,-1.20288917e+00f,-1.18607722e+00f,+4.93939016e-01f,
// -2.93688080e-01f,-2.28349231e-01f,-1.69248915e+00f,-1.38043236e+00f,-1.66819882e+00f,
// -5.93927406e-03f,+9.57198979e-01f,+8.95097882e-01f,-1.22386556e+00f,-2.13894884e-01f,
// -5.37755399e-01f,}; 
// k2c_tensor test2_fc1_input_input = {&test2_fc1_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 

// float keras_softmax_test2_array[5] = {
// +6.06754720e-02f,+1.13104470e-01f,+1.25357538e-01f,+4.50997233e-01f,+2.49865279e-01f,
// }; 
// k2c_tensor keras_softmax_test2 = {&keras_softmax_test2_array[0],1,5,{5,1,1,1,1}}; 

// float c_softmax_test2_array[5] = {0}; 
// k2c_tensor c_softmax_test2 = {&c_softmax_test2_array[0],1,5,{5,1,1,1,1}}; 

// float test3_fc1_input_input_array[16] = {
// +1.30839502e+00f,-1.92795456e+00f,+3.60128117e-02f,+4.91520641e-02f,+1.92247366e+00f,
// +4.38423586e-01f,-5.77535472e-01f,-1.63787790e+00f,+1.25333090e+00f,+1.97433270e+00f,
// +1.96195108e+00f,+6.09410054e-01f,-1.17559525e+00f,-4.52307188e-01f,-1.48806134e+00f,
// +9.64050222e-01f,}; 
// k2c_tensor test3_fc1_input_input = {&test3_fc1_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 

// float keras_softmax_test3_array[5] = {
// +6.83690235e-02f,+1.14120677e-01f,+2.96947360e-01f,+1.36957809e-01f,+3.83605093e-01f,
// }; 
// k2c_tensor keras_softmax_test3 = {&keras_softmax_test3_array[0],1,5,{5,1,1,1,1}}; 

// float c_softmax_test3_array[5] = {0}; 
// k2c_tensor c_softmax_test3 = {&c_softmax_test3_array[0],1,5,{5,1,1,1,1}}; 

// float test4_fc1_input_input_array[16] = {
// -9.72371707e-01f,+7.35564747e-01f,-3.62652351e-01f,+1.42774920e+00f,-8.77108358e-01f,
// +4.26241432e-01f,+3.41118237e-01f,+1.79913021e+00f,-5.94328508e-01f,-9.21884052e-03f,
// -1.06794723e+00f,-1.54508798e+00f,+1.14777953e+00f,+1.56599836e+00f,+1.39044705e+00f,
// -3.76941403e-01f,}; 
// k2c_tensor test4_fc1_input_input = {&test4_fc1_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 

// float keras_softmax_test4_array[5] = {
// +2.06911057e-01f,+2.55049735e-01f,+2.28265196e-01f,+1.75832480e-01f,+1.33941576e-01f,
// }; 
// k2c_tensor keras_softmax_test4 = {&keras_softmax_test4_array[0],1,5,{5,1,1,1,1}}; 

// float c_softmax_test4_array[5] = {0}; 
// k2c_tensor c_softmax_test4 = {&c_softmax_test4_array[0],1,5,{5,1,1,1,1}}; 

// float test5_fc1_input_input_array[16] = {
// -1.32740040e+00f,+8.33081998e-01f,+7.71103831e-01f,-1.71092291e+00f,+1.87499031e+00f,
// -2.51123388e-01f,-1.41717021e-01f,+7.89008066e-01f,+1.24630330e+00f,-5.19936707e-01f,
// -4.55375704e-01f,+1.96543182e+00f,+5.61706575e-01f,+7.71874198e-01f,-1.20060857e+00f,
// -1.67245427e+00f,}; 
// k2c_tensor test5_fc1_input_input = {&test5_fc1_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 

// float keras_softmax_test5_array[5] = {
// +7.48516917e-02f,+9.64650139e-02f,+1.28892452e-01f,+3.31222802e-01f,+3.68568003e-01f,
// }; 
// k2c_tensor keras_softmax_test5 = {&keras_softmax_test5_array[0],1,5,{5,1,1,1,1}}; 

// float c_softmax_test5_array[5] = {0}; 
// k2c_tensor c_softmax_test5 = {&c_softmax_test5_array[0],1,5,{5,1,1,1,1}}; 

// float test6_fc1_input_input_array[16] = {
// +1.75593184e+00f,+5.78971566e-02f,-2.61420350e-01f,-8.73099299e-01f,-1.30007323e+00f,
// -1.86497515e+00f,+1.49870831e+00f,+2.84907052e-01f,+2.98053092e-01f,-9.83856906e-01f,
// -1.04990271e+00f,+1.35694189e+00f,-1.02187795e+00f,-1.61839546e+00f,+7.66613901e-01f,
// -1.28727213e+00f,}; 
// k2c_tensor test6_fc1_input_input = {&test6_fc1_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 

// float keras_softmax_test6_array[5] = {
// +2.90911645e-02f,+3.35484952e-01f,+1.11245640e-01f,+3.99320543e-01f,+1.24857813e-01f,
// }; 
// k2c_tensor keras_softmax_test6 = {&keras_softmax_test6_array[0],1,5,{5,1,1,1,1}}; 

// float c_softmax_test6_array[5] = {0}; 
// k2c_tensor c_softmax_test6 = {&c_softmax_test6_array[0],1,5,{5,1,1,1,1}}; 

// float test7_fc1_input_input_array[16] = {
// -4.08918090e-02f,-6.13647274e-02f,-5.38667209e-02f,+1.34256545e+00f,+1.01971716e-01f,
// -1.52871842e+00f,-1.67224401e+00f,+2.87650465e-01f,-8.56455861e-01f,-1.49645611e+00f,
// +5.37883237e-01f,-1.50722092e+00f,+2.38769709e-01f,-1.78649217e-01f,-3.23353433e-01f,
// -1.86231213e+00f,}; 
// k2c_tensor test7_fc1_input_input = {&test7_fc1_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 

// float keras_softmax_test7_array[5] = {
// +3.81551571e-02f,+5.81536107e-02f,+1.16908029e-01f,+4.04545784e-01f,+3.82237375e-01f,
// }; 
// k2c_tensor keras_softmax_test7 = {&keras_softmax_test7_array[0],1,5,{5,1,1,1,1}}; 

// float c_softmax_test7_array[5] = {0}; 
// k2c_tensor c_softmax_test7 = {&c_softmax_test7_array[0],1,5,{5,1,1,1,1}}; 

// float test8_fc1_input_input_array[16] = {
// -1.18673590e+00f,-1.00147881e-01f,-2.35149789e-01f,+4.69985133e-01f,-9.82621608e-01f,
// -1.30041857e+00f,-9.52789280e-01f,-1.07704859e+00f,+7.01380689e-01f,+1.06302313e+00f,
// +1.29994578e-01f,+2.11516739e-01f,-7.92078277e-01f,-7.16424995e-02f,-1.46282496e+00f,
// +1.50434045e+00f,}; 
// k2c_tensor test8_fc1_input_input = {&test8_fc1_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 

// float keras_softmax_test8_array[5] = {
// +5.35257578e-01f,+1.42910719e-01f,+1.41292736e-01f,+7.02307746e-02f,+1.10308200e-01f,
// }; 
// k2c_tensor keras_softmax_test8 = {&keras_softmax_test8_array[0],1,5,{5,1,1,1,1}}; 

// float c_softmax_test8_array[5] = {0}; 
// k2c_tensor c_softmax_test8 = {&c_softmax_test8_array[0],1,5,{5,1,1,1,1}}; 

// float test9_fc1_input_input_array[16] = {
// -8.34375970e-01f,+2.99207977e-01f,-7.57405982e-01f,+1.32857944e+00f,-3.72757377e-01f,
// +1.81456283e+00f,-1.39286594e+00f,-1.00886385e+00f,-6.35451746e-01f,+1.83476203e-01f,
// -3.51517620e-01f,-8.57092861e-01f,-1.53326164e+00f,-7.24438554e-01f,-1.17356338e+00f,
// -2.91159927e-01f,}; 
// k2c_tensor test9_fc1_input_input = {&test9_fc1_input_input_array[0],1,16,{16, 1, 1, 1, 1}}; 

// float keras_softmax_test9_array[5] = {
// +4.99035046e-02f,+8.35608616e-02f,+5.87720215e-01f,+8.30977336e-02f,+1.95717677e-01f,
// }; 
// k2c_tensor keras_softmax_test9 = {&keras_softmax_test9_array[0],1,5,{5,1,1,1,1}}; 

// float c_softmax_test9_array[5] = {0}; 
// k2c_tensor c_softmax_test9 = {&c_softmax_test9_array[0],1,5,{5,1,1,1,1}}; 

// float test10_fc1_input_input_array[16] = {
// -1.32873867e+00f,-8.37631345e-01f,-1.28813137e+00f,+6.02816816e-01f,-2.74003360e-01f,
// -1.08468716e+00f,+2.44546422e-01f,-1.42541757e-01f,+5.65781060e-01f,-1.63453000e+00f,
// +1.21736647e+00f,-6.63205295e-01f,+7.18239382e-01f,+1.12289779e+00f,-5.59473905e-01f,
// -1.50364507e+00f,}; 
// k2c_tensor test10_fc1_input_input = {&test10_fc1_input_input_array[0],1,16,{16, 1, 1, 1, 1}};

// float keras_softmax_test10_array[5] = {
// +1.28861561e-01f,+2.70770699e-01f,+1.18411593e-01f,+2.34627888e-01f,+2.47328341e-01f,
// }; 
// k2c_tensor keras_softmax_test10 = {&keras_softmax_test10_array[0],1,5,{5,1,1,1,1}}; 

// float c_softmax_test10_array[5] = {0}; 
// k2c_tensor c_softmax_test10 = {&c_softmax_test10_array[0],1,5,{5,1,1,1,1}}; 

int main(){
    size_t i;

    test1_fc1_input_input.ndim = 1;
    test1_fc1_input_input.numel = 16;
    test1_fc1_input_input.shape[0] = 16;
    test1_fc1_input_input.shape[1] = 1;
    test1_fc1_input_input.shape[2] = 1;
    test1_fc1_input_input.shape[3] = 1;
    test1_fc1_input_input.shape[4] = 1;

    for(i=0 ; i < 16 ; i++){
        test1_fc1_input_input.array[i] = test1_fc1_input_input_array[i];
    }


    keras_softmax_test1.ndim = 1;
    keras_softmax_test1.numel = 5;
    keras_softmax_test1.shape[0] = 5;
    keras_softmax_test1.shape[1] = 1;
    keras_softmax_test1.shape[2] = 1;
    keras_softmax_test1.shape[3] = 1;
    keras_softmax_test1.shape[4] = 1;

    for(i=0 ; i < 5 ; i++){
        keras_softmax_test1.array[i] = keras_softmax_test1_array[i];
    }


    c_softmax_test1.ndim = 1;
    c_softmax_test1.numel = 5;
    c_softmax_test1.shape[0] = 5;
    c_softmax_test1.shape[1] = 1;
    c_softmax_test1.shape[2] = 1;
    c_softmax_test1.shape[3] = 1;
    c_softmax_test1.shape[4] = 1;

    for(i=0 ; i < 5 ; i++){
        c_softmax_test1.array[i] = c_softmax_test1_array[i];
    }


    float errors[10];
    size_t num_tests = 1; //10; 
    size_t num_outputs = 1; 
    check_best_model_initialize(); 
    clock_t t0 = clock(); 
    check_best_model(&test1_fc1_input_input,&c_softmax_test1); 
    // check_best_model(&test2_fc1_input_input,&c_softmax_test2); 
    // check_best_model(&test3_fc1_input_input,&c_softmax_test3); 
    // check_best_model(&test4_fc1_input_input,&c_softmax_test4); 
    // check_best_model(&test5_fc1_input_input,&c_softmax_test5); 
    // check_best_model(&test6_fc1_input_input,&c_softmax_test6); 
    // check_best_model(&test7_fc1_input_input,&c_softmax_test7); 
    // check_best_model(&test8_fc1_input_input,&c_softmax_test8); 
    // check_best_model(&test9_fc1_input_input,&c_softmax_test9); 
    // check_best_model(&test10_fc1_input_input,&c_softmax_test10); 

    clock_t t1 = clock(); 
    printf("Average time over 10 tests: %e s \n", 
    ((double)t1-t0)/(double)CLOCKS_PER_SEC/(double)10); 
    errors[0] = maxabs(&keras_softmax_test1,&c_softmax_test1); 
    // errors[1] = maxabs(&keras_softmax_test2,&c_softmax_test2); 
    // errors[2] = maxabs(&keras_softmax_test3,&c_softmax_test3); 
    // errors[3] = maxabs(&keras_softmax_test4,&c_softmax_test4); 
    // errors[4] = maxabs(&keras_softmax_test5,&c_softmax_test5); 
    // errors[5] = maxabs(&keras_softmax_test6,&c_softmax_test6); 
    // errors[6] = maxabs(&keras_softmax_test7,&c_softmax_test7); 
    // errors[7] = maxabs(&keras_softmax_test8,&c_softmax_test8); 
    // errors[8] = maxabs(&keras_softmax_test9,&c_softmax_test9); 
    // errors[9] = maxabs(&keras_softmax_test10,&c_softmax_test10); 

    float maxerror = errors[0]; 
    for( i=0; i < num_tests*num_outputs;i++){                 // made 1->0
        if (errors[i] > maxerror) { 
            maxerror = errors[i];}
    } 

    printf("Max absolute error for 10 tests: %e \n", maxerror);
    check_best_model_terminate(); 

    if (maxerror > 1e-05) { 
        return 1;
    } 
    return 0;
} 

float maxabs(k2c_tensor *tensor1, k2c_tensor *tensor2){ 

    float x = 0; 

    float y = 0; 

    for(size_t i=0; i<tensor1->numel; i++){

    y = fabsf(tensor1->array[i]-tensor2->array[i]);
    if (y>x) {x=y;}}
    return x;
}

