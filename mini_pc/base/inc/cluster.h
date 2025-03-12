#ifndef CLUSTER_H
#define CLUSTER_H

//all clusters have same fixed size of 4 bits
//all bits equivalent of boolean (byte) for now

class Cluster
{
public:
  Cluster();
  Cluster(const bool&, const bool&, const bool&, const bool&);
  Cluster(const Cluster&);

  Cluster& operator=(const Cluster&);
  bool& operator[](const unsigned&) const;

  short toDecimal();
  Cluster& inverse();
  short getSize();

protected:
  static const short size = 4;
  bool* array = new bool[size];
};

#endif //CLUSTER_H
