#include "net.h"

Net::Net()
{
}
void Net::getResults(vector<double> &resultVals) const
{
        resultVals.clear();

        for (unsigned n = 0; n < m_layers.back().size() - 1; ++n) {
                resultVals.push_back(m_layers.back()[n].getOutputVal());
        }
}

void Net::backProp(const vector<double> &targetVals)
{
        // Perhitungan error net

        Layer &outputLayer = m_layers.back();
        m_error = 0.0;

        for (unsigned n = 0; n < outputLayer.size() - 1; ++n) {
                double delta = targetVals[n] - outputLayer[n].getOutputVal();
                m_error += delta * delta;
        }
        m_error /= outputLayer.size() - 1;  // Mean Squared Error (MSE)
        m_error = sqrt(m_error); // RMS



        // Perhitungan gradient output layer

        for (unsigned n = 0; n < outputLayer.size() - 1; ++n) {
                outputLayer[n].hitungOutputGradien(targetVals[n]);
        }

        // Perhitungan gradient hidden layer

        for (unsigned layerNum = m_layers.size() - 2; layerNum > 0; --layerNum) {
                Layer &hiddenLayer = m_layers[layerNum];
                Layer &layerSelanjutnya = m_layers[layerNum + 1];

                for (unsigned n = 0; n < hiddenLayer.size(); ++n) {
                        hiddenLayer[n].hitungHiddenGradien(layerSelanjutnya);
                }
        }

        // update weight

        for (unsigned layerNum = m_layers.size() - 1; layerNum > 0; --layerNum) {
                Layer &layer = m_layers[layerNum];
                Layer &layerSebelumnya = m_layers[layerNum - 1];

                for (unsigned n = 0; n < layer.size() - 1; ++n) {
                        layer[n].updateInputWeight(layerSebelumnya);
                }
        }
}

void Net::feedForward(const vector<double> &inputVals)
{
        assert(inputVals.size() == m_layers[0].size() - 1);

        // Inisialisasi input layer ke setiap neuron di layer pertama
        for (unsigned i = 0; i < inputVals.size(); ++i) {
                m_layers[0][i].setOutputVal(inputVals[i]);
        }

        // forward propagate
        for (unsigned layerNum = 1; layerNum < m_layers.size(); ++layerNum) {
                Layer &layerSebelumnya = m_layers[layerNum - 1];
                for (unsigned n = 0; n < m_layers[layerNum].size() - 1; ++n) {
                        m_layers[layerNum][n].feedForward(layerSebelumnya);
                }
        }
}

void Net::setTopology(const vector<unsigned> &topology)
{
        unsigned numLayers = topology.size();
        for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum) {
                m_layers.push_back(Layer());
                unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];

                // Buat neuron dan bias untuk setiap layer
                for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum) {
                        m_layers.back().push_back(Neuron(numOutputs, neuronNum));
                        //cout<<"neuron "<<neuronNum<<" ";
                }
                //cout<<endl;



                // isi setiap nilai bias dgn 1 :
                m_layers.back().back().setOutputVal(1.0);
        }
}
