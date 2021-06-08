#include "InterfaceVector.h"

int ChooseTypeVector() {
    int type;
    cout << "�������� ���, � ������� ������ ��������: \n"
        << "\t1: int\n"
        << "\t2: float\n"
        << "\t3: complex\n"
        << "������� �����: ";
    cin >> type;

    return type;
}

int ChooseFunctionVector() {
    int func;
    cout << "�������� �������, ������� ����� ���������� ��� ���������: \n"
        << "\t1: ����������� \n"
        << "\t2: ��������� ������� �� ������\n"
        << "\t3: ��������� ������� �� ������\n"
        << "\t4: �������� ����� �������\n"
        << "\t5: �������� ����� �������\n"
        << "\t6: ��������� ������������\n"
        << "\t7: ����� ����������\n"
        << "\t8: ���������� ���������\n"
        << "������� �����: ";
    cin >> func;

    return func;
}

void InterfaceVector() {

    int type = ChooseTypeVector();
    if (type == 1) {
        cout << "������� 2 �������:\n";
        cout << "������� ����������� �������: \n";
        int l1;
        cin >> l1;
        cout << "������������: \n";
        int* data1 = new int[l1];
        for (int i = 0; i < l1; i++)
            cin >> data1[i];
        Vector<int>* Data1 = new Vector<int>(data1, l1);
        cout << "������� ����� ������: \n";
        int l2;
        cin >> l2;
        cout << "������������: \n";
        int* data2 = new int[l2];
        for (int i = 0; i < l2; i++)
            cin >> data2[i];
        Vector<int>* Data2 = new Vector<int>(data2, l2);
        cout << "���� �����\n";
        Data1->PrintinfoVec();
        Data2->PrintinfoVec();
        int usch = 0;
        while (usch != 8) {
            int usch = ChooseFunctionVector();
            switch (usch)
            {
            case 1: {
                cout << "\n����� ���� ��������\n";
                Vector<int>* Sum = new Vector<int>(*Data1);
                Sum->SumVec(*Data2);
                Sum->PrintinfoVec();
                break;
            }
            case 2: {
                cout << "\n������� ��������\n";
                int x;
                cin >> x;
                Data1->MultScalar(x);
                Data1->PrintinfoVec();
                break;
            }
            case 3: {
                cout << "\n������� ��������\n";
                int x;
                cin >> x;
                Data2->MultScalar(x);
                Data2->PrintinfoVec();
                break;
            }
            case 4: {
                cout << "����� ������� ����� " << Data1->Norm() << "\n";
                break;
            }
            case 5: {
                cout << "����� ������� ����� " << Data2->Norm() << "\n";
                break;
            }
            case 6: {
                Vector<int>* Mul = new Vector<int>(*Data1);
                Mul->MultVec(*Data2);
                Mul->PrintinfoVec();
                break;
            }
            case 7: {
                Data1->PrintinfoVec();
                Data2->PrintinfoVec();
                break;
            }
            case 8: {
                break;
            }
            default:
                break;
            }
            if (usch == 8) break;
        }
    }

    if (type == 2) {
        cout << "������� 2 �������:\n";
        cout << "������� ����������� �������: \n";
        int l1;
        cin >> l1;
        cout << "������������: \n";
        double* data1 = new double[l1];
        for (int i = 0; i < l1; i++)
            cin >> data1[i];
        Vector<double>* Data1 = new Vector<double>(data1, l1);
        cout << "������� ����� ������: \n";
        int l2;
        cin >> l2;
        cout << "������������: \n";
        double* data2 = new double[l2];
        for (int i = 0; i < l2; i++)
            cin >> data2[i];
        Vector<double>* Data2 = new Vector<double>(data2, l2);
        cout << "���� �����\n";
        Data1->PrintinfoVec();
        Data2->PrintinfoVec();
        int usch = 0;
        while (usch != 8) {
            int usch = ChooseFunctionVector();
            switch (usch)
            {
            case 1: {
                cout << "\n����� ���� ��������\n";
                Vector<double>* Sum = new Vector<double>(*Data1);
                Sum->SumVec(*Data2);
                Sum->PrintinfoVec();
                break;
            }
            case 2: {
                cout << "\n������� ��������\n";
                double x;
                cin >> x;
                Data1->MultScalar(x);
                Data1->PrintinfoVec();
                break;
            }
            case 3: {
                cout << "\n������� ��������\n";
                double x;
                cin >> x;
                Data2->MultScalar(x);
                Data2->PrintinfoVec();
                break;
            }
            case 4: {
                cout << "����� ������� ����� " << Data1->Norm() << "\n";
                break;
            }
            case 5: {
                cout << "����� ������� ����� " << Data2->Norm() << "\n";
                break;
            }
            case 6: {
                Vector<double>* Mul = new Vector<double>(*Data1);
                Mul->MultVec(*Data2);
                Mul->PrintinfoVec();
                break;
            }
            case 7: {
                Data1->PrintinfoVec();
                Data2->PrintinfoVec();
                break;
            }
            case 8: {
                break;
            }
            default:
                break;
            }
            if (usch == 8) break;
        }
    }

    if (type == 3) {
        cout << "������� 2 �������:\n";
        cout << "������� ����������� �������: \n";
        int l1;
        cin >> l1;
        cout << "������������: \n";
        Complex* data1 = new Complex[l1];
        for (int i = 0; i < l1; i++)
            cin >> data1[i];
        Vector<Complex>* Data1 = new Vector<Complex>(data1, l1);
        cout << "������� ����� ������: \n";
        int l2;
        cin >> l2;
        cout << "������������: \n";
        Complex* data2 = new Complex[l2];
        for (int i = 0; i < l2; i++)
            cin >> data2[i];
        Vector<Complex>* Data2 = new Vector<Complex>(data2, l2);
        cout << "���� �����\n";
        Data1->PrintinfoVec();
        Data2->PrintinfoVec();
        int usch = 0;
        while (usch != 8) {
            int usch = ChooseFunctionVector();
            switch (usch)
            {
            case 1: {
                cout << "\n����� ���� ��������\n";
                Vector<Complex>* Sum = new Vector<Complex>(*Data1);
                Sum->SumVec(*Data2);
                Sum->PrintinfoVec();
                break;
            }
            case 2: {
                cout << "\n������� ��������\n";
                Complex x;
                cin >> x;
                Data1->MultScalar(x);
                Data1->PrintinfoVec();
                break;
            }
            case 3: {
                cout << "\n������� ��������\n";
                Complex x;
                cin >> x;
                Data2->MultScalar(x);
                Data2->PrintinfoVec();
                break;
            }
            case 4: {
                //cout << "����� ������� ����� " << Data1->Norm() << "\n";
                break;
            }
            case 5: {
                //cout << "����� ������� ����� " << Data2->Norm() << "\n";
                break;
            }
            case 6: {
                Vector<Complex>* Mul = new Vector<Complex>(*Data1);
                Mul->MultVec(*Data2);
                Mul->PrintinfoVec();
                break;
            }
            case 7: {
                Data1->PrintinfoVec();
                Data2->PrintinfoVec();
                break;
            }
            case 8: {
                break;
            }
            default:
                break;
            }
            if (usch == 8) break;
        }
    }

}