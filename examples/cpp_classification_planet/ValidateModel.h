#pragma once
#include <string>
#include <vector>
using namespace std;
class CValidateModel
{
public:
  CValidateModel(string strModelRoot, string strTrainedFile, string strImgRoot, string strTestListFile, int gpuNum);
    ~CValidateModel();

private:
  void InitModel(string strModelRoot, string strTrainedFile, string strImgRoot, string strTestListFile, int gpuNum);
  void testValidateSet();

	int m_nOverSample;
	int m_nBatchSize;
	string m_model_file;
	string m_trained_file;
	string m_mean_file;
	string m_label_file;
	string m_ValidateListFile;

	string m_ImgRoot;
	string m_strSavePredictResult;

    struct stValSetIntel
    {
      string strPath;
      string strOrginCode;
      string strPredictCode;
      float fProb[3];
    };
    vector<stValSetIntel> m_vValidateIntelList;

	CaffeClassifier m_classifier;
	vector<string> m_label;

public:
	static inline int zeroCheck(int n)
	{
		if (n == 0)
			return 1;
		return n;
	}
};

