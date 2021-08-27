// x % m[i] = r[i] % m[i] を満たす正で最小の x を返す
// i!=j に対して gcd(m[i], m[j])=1 であると仮定
// とりあえず解の存在判定は保留
ll ext_gcd(ll a,ll b,ll &x,ll &y){
    if(a<b)swap(a,b);
    if(b==0){
        x==1;
        y==0;
        return a;
    }
    ll x2=0,y2 = 0;
    ll d = ext_gcd(b,a%b,x2,y2);
    x = y2;
    y = x2 - (a/b)*y2;
    return d;
}


ll mod_inv(ll a,ll m){
    ll x,y;
    ll d = ext_gcd(a,m,x,y);
    if(d!=1){
        return -1;
    }
    x %= m;
    if(x<0)x += m;
    return x;
}


ll garner(vector<ll> r,vector<ll>m){
    int n = r.size();
    ll m_prod = 1;
    ll x = r[0]%m[0];
    for(int i=1;i<n;i++){
        m_prod *= m[i-1];
        ll t = ((r[i]-x)*mod_inv(m_prod,m[i]))%m[i];
        if(t<0)t+=m[i];
        x += t*m_prod;
    }
    return x;
}