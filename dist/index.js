"use strict";var I=function(r,i){return function(){return i||r((i={exports:{}}).exports,i),i.exports}};var p=I(function(k,q){
function O(r){return r===0?.3999999999940942:.3999999999940942+r*(.22222198432149784+r*.15313837699209373)}q.exports=O
});var A=I(function(m,c){
function h(r){return r===0?.6666666666666735:.6666666666666735+r*(.2857142874366239+r*(.1818357216161805+r*.14798198605116586))}c.exports=h
});var M=I(function(w,L){
var E=require('@stdlib/number-float64-base-get-high-word/dist'),y=require('@stdlib/number-float64-base-set-high-word/dist'),P=require('@stdlib/math-base-assert-is-nan/dist'),R=require('@stdlib/constants-float64-exponent-bias/dist'),S=require('@stdlib/constants-float64-ninf/dist'),X=p(),g=A(),_=.6931471803691238,o=19082149292705877e-26,D=0x40000000000000,W=.3333333333333333,G=1048575,d=2146435072,B=1048576,F=1072693248;function T(r){var i,t,H,N,a,v,e,f,l,u,n,s;return r===0?S:P(r)||r<0?NaN:(t=E(r),a=0,t<B&&(a-=54,r*=D,t=E(r)),t>=d?r+r:(a+=(t>>20)-R|0,t&=G,f=t+614244&1048576|0,r=y(r,t|f^F),a+=f>>20|0,e=r-1,(G&2+t)<3?e===0?a===0?0:a*_+a*o:(v=e*e*(.5-W*e),a===0?e-v:a*_-(v-a*o-e)):(u=e/(2+e),s=u*u,f=t-398458|0,n=s*s,l=440401-t|0,N=n*X(n),H=s*g(n),f|=l,v=H+N,f>0?(i=.5*e*e,a===0?e-(i-u*(i+v)):a*_-(i-(u*(i+v)+a*o)-e)):a===0?e-u*(e-v):a*_-(u*(e-v)-a*o-e))))}L.exports=T
});var b=M();module.exports=b;
/** @license Apache-2.0 */
/** @license Apache-2.0 */
/** @license Apache-2.0 */
//# sourceMappingURL=index.js.map
