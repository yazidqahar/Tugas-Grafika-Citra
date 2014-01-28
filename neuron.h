#ifndef NEURON_H
#define NEURON_H
#include <vector>
#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <cmath>
#include <sstream>
#include <iomanip>

        using namespace std;

struct Connection
{
    double weight;
    double deltaWeight;
};
class Neuron;
typedef vector<Neuron> Layer;

class Neuron
{
public:
    Neuron(unsigned numOutputs, unsigned myIndex);
    void setOutputVal(double val) { m_outputVal = val; }
    double getOutputVal(void) const { return m_outputVal; }
    void feedForward(const Layer &layerSebelumnya);
    void hitungOutputGradien(double targetVal);
    void hitungHiddenGradien(const Layer &layerSelanjutnya);
    void updateInputWeight(Layer &layerSebelumnya);
    static double eta;
    static double alpha;
    static double transferFunction(double x);
    static double transferFunctionTurunan(double x);
    static double weightAcak(void) { return rand() / double(RAND_MAX); }
    double sumDOW(const Layer &layerSelanjutnya) const;
    double m_outputVal;
    vector<Connection> m_outputWeights;
    unsigned m_myIndex;
    double m_gradient;
};


#endif // NEURON_H
