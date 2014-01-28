#include "neuron.h"
#include <math.h>

double Neuron::eta = 0.25;
double Neuron::alpha = 0.5;

void Neuron::updateInputWeight(Layer &layerSebelumnya)
{
        for (unsigned n = 0; n < layerSebelumnya.size(); ++n) {
                Neuron &neuron = layerSebelumnya[n];
                double deltaWeightDulu = neuron.m_outputWeights[m_myIndex].deltaWeight;

                double deltaWeightBaru =
                                eta
                                * neuron.getOutputVal()
                                * m_gradient
                                + alpha
                                * deltaWeightDulu;

                neuron.m_outputWeights[m_myIndex].deltaWeight = deltaWeightBaru;
                neuron.m_outputWeights[m_myIndex].weight += deltaWeightBaru;
        }


}

double Neuron::sumDOW(const Layer &layerSelanjutnya) const
{
        double sum = 0.0;

        // Sum [w * gradien]

        for (unsigned n = 0; n < layerSelanjutnya.size() - 1; ++n) {
                sum += m_outputWeights[n].weight * layerSelanjutnya[n].m_gradient;
        }

        return sum;
}

void Neuron::hitungHiddenGradien(const Layer &layerSelanjutnya)
{
        double dow = sumDOW(layerSelanjutnya);
        m_gradient = dow * Neuron::transferFunctionTurunan(m_outputVal);
}

void Neuron::hitungOutputGradien(double targetVal)
{
        double delta = targetVal - m_outputVal;
        m_gradient = delta * Neuron::transferFunctionTurunan(m_outputVal);
}

double Neuron::transferFunction(double x)
{
        //sigmoid
        return 1 / (1 + exp(-1 * x));
}

double Neuron::transferFunctionTurunan(double x)
{
        //turunan sigmoid
        return (1 / (1 + exp(-1 * x))) * ( 1 - ( 1 / (1 + exp(-1 * x)) ) );
    //return exp(-1 * x) / ((1 + exp(-1 * x)) * (1 + exp(-1 * x)));
}

void Neuron::feedForward(const Layer &layerSebelumnya)
{
        double sum = 0.0;

        // penjumlahan layer sebelumnya (input termasuk bias)

        for (unsigned n = 0; n < layerSebelumnya.size(); ++n) {
                sum += layerSebelumnya[n].getOutputVal() *
                                layerSebelumnya[n].m_outputWeights[m_myIndex].weight;
        }

        m_outputVal = Neuron::transferFunction(sum);
}

Neuron::Neuron(unsigned numOutputs, unsigned myIndex)
{
        for (unsigned c = 0; c < numOutputs; ++c) {
                m_outputWeights.push_back(Connection());
                m_outputWeights.back().weight = weightAcak();
        }

        m_myIndex = myIndex;
}
