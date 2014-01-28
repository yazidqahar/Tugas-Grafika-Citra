#ifndef NET_H
#define NET_H
#include "neuron.h"

class Net
{
public:
    Net();
    void setTopology(const vector<unsigned> &topology);
    void feedForward(const vector<double> &inputVals);
    void backProp(const vector<double> &targetVals);
    void getResults(vector<double> &resultVals) const;
    double getError(void) const { return m_error; }
    vector<Layer> m_layers;
    double m_error;
};

#endif // NET_H
