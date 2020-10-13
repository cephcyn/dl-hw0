#include <assert.h>
#include <math.h>
#include "uwnet.h"

// Run an activation function on each element in a matrix,
// modifies the matrix in place
// matrix m: Input to activation function
// ACTIVATION a: function to run
void activate_matrix(matrix m, ACTIVATION a)
{
    int i, j;
    for(i = 0; i < m.rows; ++i){
        double sum = 0;
        for(j = 0; j < m.cols; ++j){
            double x = m.data[i*m.cols + j];
            double actX;
            if(a == LOGISTIC){
                // TODO
                actX = 1 / (1 + exp(-x));
            } else if (a == RELU){
                // TODO
                if (x <= 0) {
                    actX = 0;
                } else {
                    actX = x;
                }
            } else if (a == LRELU){
                // TODO
                if (x < 0) {
                    actX = 0.01 * x;
                } else {
                    actX = x;
                }
            } else if (a == SOFTMAX){
                // TODO
                actX = exp(x);
            }
            m.data[i*m.cols + j] = actX;  // Update matrix with activated x
            sum += m.data[i*m.cols + j];
        }
        if (a == SOFTMAX) {
            // TODO: have to normalize by sum if we are using SOFTMAX
            for (int k = 0; i < m.cols; ++k) {
                m.data[i*m.cols + k] /= sum;
            }
        }
    }
}

// Calculates the gradient of an activation function and multiplies it into
// the delta for a layer
// matrix m: an activated layer output
// ACTIVATION a: activation function for a layer
// matrix d: delta before activation gradient
void gradient_matrix(matrix m, ACTIVATION a, matrix d)
{
    int i, j;
    for(i = 0; i < m.rows; ++i){
        for(j = 0; j < m.cols; ++j){
            double x = m.data[i*m.cols + j];
            // TODO: multiply the correct element of d by the gradient
        }
    }
}
