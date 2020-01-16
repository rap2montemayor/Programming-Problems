#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,p; cin>>n>>p;
    int countriesCount=0;
    vector<int> aCountries(n,-1);

    while (p--) {
        int a1,a2; cin>>a1>>a2;
        if (aCountries[a1]==-1 and aCountries[a2]==-1) {
            aCountries[a1]=countriesCount;
            aCountries[a2]=countriesCount;
            countriesCount++;
        }
        else {
            if (aCountries[a1]!=-1)
                aCountries[a2]=aCountries[a1];
            else
                aCountries[a1]=aCountries[a2];
        }
    }
    for (int i=0; i<n; i++)
        if (aCountries[i]==-1)
            aCountries[i]=countriesCount++;

    vector<int> aInCountry(countriesCount);
    for (int i : aCountries) aInCountry[i]++;
    
    int ans=0;
    for (int i=0; i<countriesCount; i++)
        for (int j=i+1; j<countriesCount; j++)
            ans+=aInCountry[j]*aInCountry[i];

    cout << ans << endl;

    return 0;
}
