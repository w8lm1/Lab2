#include "InterfaceLinearForm.h"

int ChooseType() {
    int type;
    cout << "�������� ���, � ������� ������ ��������: \n"
        << "\t1: int\n"
        << "\t2: float\n"
        << "\t3: complex\n"
        << "������� �����: ";
    cin >> type;

    return type;
}

int ChooseFunction() {
    int func;
    cout << "�������� �������, ������� ����� ���������� ��� ���������: \n"
        << "\t1: ����������� \n"
        << "\t2: ������� ���� �� �������\n"
        << "\t3: ��������� �������\n"
        << "\t4: ��������� �������\n"
        << "\t5: �������� �������\n"
        << "\t6: �������� �������\n"
        << "\t7: ����� ����������\n"
        << "\t8: ���������� ���������\n"
        << "������� �����: ";
    cin >> func;

    return func;
}

void InterfaceLinearForm() {
    
    int type = ChooseType();
    if (type == 1) {
        cout << "������� 2 �������� �����:\n";
        cout << "������� ����� ������: \n";
        int l1;
        cin >> l1;
        cout << "������������: \n";
        int* data1 = new int[l1];
        for (int i = 0; i < l1; i++)
            cin >> data1[i];
        LiniarForm<int>* Data1 = new LiniarForm<int>(data1, l1);
        cout << "������� ����� ������: \n";
        int l2;
        cin >> l2;
        cout << "������������: \n";
        int* data2 = new int[l2];
        for (int i = 0; i < l2; i++)
            cin >> data2[i];
        LiniarForm<int>* Data2 = new LiniarForm<int>(data2, l2);
        cout << "���� �����\n";
        Data1->Printinfo();
        Data2->Printinfo();
        int usch = 0;
        while (usch != 8) {
            int usch = ChooseFunction();
            switch (usch)
            {
            case 1: {
                cout << "\n����� ���� ����\n";
                LiniarForm<int>* Sum = new LiniarForm<int>(*Data1);
                Sum->Sum(*Data2);
                Sum->Printinfo();
                break;
            }
            case 2: {
                cout << "\n��������� ������ ����� �� ������\n";
                LiniarForm<int>* Min = new LiniarForm<int>(*Data1);
                Min->Subtraction(*Data2);
                Min->Printinfo();
                cout << "\n��������� ������ ����� �� ������\n";

                LiniarForm<int>* Min2 = new LiniarForm<int>(*Data2);
                Min2->Subtraction(*Data1);
                Min2->Printinfo();
                break;
            }
            case 3: {
                cout << "\n������� ��������\n";
                int x;
                cin >> x;
                Data1->Multiplication(x);
                Data1->Printinfo();
                break;
            }
            case 4: {
                cout << "\n������� ��������\n";
                int x;
                cin >> x;
                Data2->Multiplication(x);
                Data2->Printinfo();
                break;
            }
            case 5: {
                cout << "\n������� �������� ����������\n";
                ArraySequence<int>* data = new ArraySequence<int>;
                for (int i = 0; i < Data1->GetSize(); i++) {
                    int x;
                    cin >> x;
                    data->Append(x);
                }

                int da = Data1->value(data);
                cout << "\n" << da << "\n";
                break;
            }
            case 6: {
                cout << "\n������� �������� ����������\n";
                ArraySequence<int>* data = new ArraySequence<int>;
                for (int i = 0; i < Data2->GetSize(); i++) {
                    int x;
                    cin >> x;
                    data->Append(x);
                }
                int da = Data2->value(data);
                cout << "\n" << da << "\n";
                break;
            }
            case 7: {
                Data1->Printinfo();
                Data2->Printinfo();
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
        cout << "������� 2 �������� �����:\n";
        cout << "������� ����� ������: \n";
        int l1;
        cin >> l1;
        cout << "������������: \n";
        double* data1 = new double[l1];
        for (int i = 0; i < l1; i++)
            cin >> data1[i];
        LiniarForm<double>* Data1 = new LiniarForm<double>(data1, l1);
        cout << "������� ����� ������: \n";
        int l2;
        cin >> l2;
        cout << "������������: \n";
        double* data2 = new double[l2];
        for (int i = 0; i < l2; i++)
            cin >> data2[i];
        LiniarForm<double>* Data2 = new LiniarForm<double>(data2, l2);
        cout << "���� �����\n";
        Data1->Printinfo();
        Data2->Printinfo();
        int usch = 0;
        while (usch != 8) {
            int usch = ChooseFunction();
            switch (usch)
            {
            case 1: {
                cout << "\n����� ���� ����\n";
                LiniarForm<double>* Sum = new LiniarForm<double>(*Data1);
                Sum->Sum(*Data2);
                Sum->Printinfo();
                break;
            }
            case 2: {
                cout << "\n��������� ������ ����� �� ������\n";
                LiniarForm<double>* Min = new LiniarForm<double>(*Data1);
                Min->Subtraction(*Data2);
                Min->Printinfo();
                cout << "\n��������� ������ ����� �� ������\n";

                LiniarForm<double>* Min2 = new LiniarForm<double>(*Data2);
                Min2->Subtraction(*Data1);
                Min2->Printinfo();
                break;
            }
            case 3: {
                cout << "\n������� ��������\n";
                double x;
                cin >> x;
                Data1->Multiplication(x);
                Data1->Printinfo();
                break;
            }
            case 4: {
                cout << "\n������� ��������\n";
                double x;
                cin >> x;
                Data2->Multiplication(x);
                Data2->Printinfo();
                break;
            }
            case 5: {
                cout << "\n������� �������� ����������\n";
                ArraySequence<double>* data = new ArraySequence<double>;
                for (int i = 0; i < Data1->GetSize(); i++) {
                    double x;
                    cin >> x;
                    data->Append(x);
                }

                double da = Data1->value(data);
                cout << "\n" << da << "\n";
                break;
            }
            case 6: {
                cout << "\n������� �������� ����������\n";
                ArraySequence<double>* data = new ArraySequence<double>;
                for (int i = 0; i < Data2->GetSize(); i++) {
                    double x;
                    cin >> x;
                    data->Append(x);
                }
                double da = Data2->value(data);
                cout << "\n" << da << "\n";
                break;
            }
            case 7: {
                Data1->Printinfo();
                Data2->Printinfo();
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
        cout << "������� 2 �������� �����:\n";
        cout << "������� ����� ������: \n";
        int l1;
        cin >> l1;
        cout << "������������: \n";
        Complex* data1 = new Complex[l1];
        for (int i = 0; i < l1; i++)
            cin >> data1[i];
        LiniarForm<Complex>* Data1 = new LiniarForm<Complex>(data1, l1);
        cout << "������� ����� ������: \n";
        int l2;
        cin >> l2;
        cout << "������������: \n";
        Complex* data2 = new Complex[l2];
        for (int i = 0; i < l2; i++)
            cin >> data2[i];
        LiniarForm<Complex>* Data2 = new LiniarForm<Complex>(data2, l2);
        cout << "���� �����\n";
        Data1->Printinfo();
        Data2->Printinfo();
        int usch = 0;
        while (usch != 8) {
            int usch = ChooseFunction();
            switch (usch)
            {
            case 1: {
                cout << "\n����� ���� ����\n";
                LiniarForm<Complex>* Sum = new LiniarForm<Complex>(*Data1);
                Sum->Sum(*Data2);
                Sum->Printinfo();
                break;
            }
            case 2: {
                cout << "\n��������� ������ ����� �� ������\n";
                LiniarForm<Complex>* Min = new LiniarForm<Complex>(*Data1);
                Min->Subtraction(*Data2);
                Min->Printinfo();
                cout << "\n��������� ������ ����� �� ������\n";

                LiniarForm<Complex>* Min2 = new LiniarForm<Complex>(*Data2);
                Min2->Subtraction(*Data1);
                Min2->Printinfo();
                break;
            }
            case 3: {
                cout << "\n������� ��������\n";
                Complex x;
                cin >> x;
                Data1->Multiplication(x);
                Data1->Printinfo();
                break;
            }
            case 4: {
                cout << "\n������� ��������\n";
                Complex x;
                cin >> x;
                Data2->Multiplication(x);
                Data2->Printinfo();
                break;
            }
            case 5: {
                cout << "\n������� �������� ����������\n";
                ArraySequence<Complex>* data = new ArraySequence<Complex>;
                for (int i = 0; i < Data1->GetSize(); i++) {
                    Complex x;
                    cin >> x;
                    data->Append(x);
                }

                Complex da = Data1->value(data);
                cout << "\n" << da << "\n";
                break;
            }
            case 6: {
                cout << "\n������� �������� ����������\n";
                ArraySequence<Complex>* data = new ArraySequence<Complex>;
                for (int i = 0; i < Data2->GetSize(); i++) {
                    Complex x;
                    cin >> x;
                    data->Append(x);
                }
                Complex da = Data2->value(data);
                cout << "\n" << da << "\n";
                break;
            }
            case 7: {
                Data1->Printinfo();
                Data2->Printinfo();
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