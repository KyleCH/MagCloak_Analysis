/**
 *
 */

makePlots_results_v6()
{

  gStyle->SetOptStat(0);

  // Results file format:
  //   bext = M[:,0]
  //   bext_err = M[:,1]
  //   bint = M[:,2]
  //   bint_err = M[:,3]
  //   bshield = M[:,4]
  //   bshield_err = M[:,5]
  //   shielding_factor = M[:,6]
  //   shielding_factor_err = M[:,7]
  //   chi2red = M[:,8]
  //   fit type = M[:,9]
  
  TTree *t_adj = new TTree();
  t_adj->ReadFile("../analysis/python/run046_2layer_helix_adj/fit_results.txt","bext/F:bext_err:bin:bin_err:bshield:bshield_err:shielding_factor:shielding_factor_err:chi2red:fittype");
  //t_adj->ReadFile("../analysis/python/run047_2layer_helix_adj/fit_results.txt","bext/F:bext_err:bin:bin_err:bshield:bshield_err:shielding_factor:shielding_factor_err:chi2red:fittype");

  TTree *t_sep = new TTree();
  t_sep->ReadFile("../analysis/python/run048_2layer_helix_spaced/fit_results.txt","bext/F:bext_err:bin:bin_err:bshield:bshield_err:shielding_factor:shielding_factor_err:chi2red:fittype");

  TTree *t_adj4 = new TTree();
  t_adj4->ReadFile("../analysis/python/run051_4layer_helix_adj/fit_results.txt","bext/F:bext_err:bin:bin_err:bshield:bshield_err:shielding_factor:shielding_factor_err:chi2red:fittype");

  TTree *t_sep4 = new TTree();
  t_sep4->ReadFile("../analysis/python/run052_4layer_helix_spaced/fit_results.txt","bext/F:bext_err:bin:bin_err:bshield:bshield_err:shielding_factor:shielding_factor_err:chi2red:fittype");

  TTree *t_adj5 = new TTree();
  t_adj5->ReadFile("../analysis/python/run053_5layer_helix_adj/fit_results.txt","bext/F:bext_err:bin:bin_err:bshield:bshield_err:shielding_factor:shielding_factor_err:chi2red:fittype");

  TTree *t_adj5noCu = new TTree();
  t_adj5noCu->ReadFile("../analysis/python/run054_5layer_no_cu/fit_results.txt","bext/F:bext_err:bin:bin_err:bshield:bshield_err:shielding_factor:shielding_factor_err:chi2red:fittype");

  // -----

  t_adj->Draw("bshield:bext:bshield_err","","");
  TGraphErrors* g_bshield_adj = new TGraphErrors( t_adj->GetEntries(""), t_adj->GetV2(), t_adj->GetV1(), 0, t_adj->GetV3() );
  g_bshield_adj->SetLineColor(kBlue);
  g_bshield_adj->SetMarkerColor(kBlue);
  g_bshield_adj->SetMarkerStyle(20);
  g_bshield_adj->SetMarkerSize(1.1);

  t_sep->Draw("bshield:bext:bshield_err","","");
  TGraphErrors* g_bshield_sep = new TGraphErrors( t_sep->GetEntries(""), t_sep->GetV2(), t_sep->GetV1(), 0, t_sep->GetV3() );
  g_bshield_sep->SetLineColor(kGreen+1);
  g_bshield_sep->SetMarkerColor(kGreen+1);
  g_bshield_sep->SetMarkerStyle(20);
  g_bshield_sep->SetMarkerSize(1.1);

  t_adj4->Draw("bshield:bext:bshield_err","","");
  TGraphErrors* g_bshield_adj4 = new TGraphErrors( t_adj4->GetEntries(""), t_adj4->GetV2(), t_adj4->GetV1(), 0, t_adj4->GetV3() );
  g_bshield_adj4->SetLineColor(kBlue);
  g_bshield_adj4->SetMarkerColor(kBlue);
  g_bshield_adj4->SetMarkerStyle(21);
  g_bshield_adj4->SetMarkerSize(1.1);

  t_sep4->Draw("bshield:bext:bshield_err","","");
  TGraphErrors* g_bshield_sep4 = new TGraphErrors( t_sep4->GetEntries(""), t_sep4->GetV2(), t_sep4->GetV1(), 0, t_sep4->GetV3() );
  g_bshield_sep4->SetLineColor(kGreen+1);
  g_bshield_sep4->SetMarkerColor(kGreen+1);
  g_bshield_sep4->SetMarkerStyle(21);
  g_bshield_sep4->SetMarkerSize(1.1);



  t_adj5->Draw("bshield:bext:bshield_err","","");
  TGraphErrors* g_bshield_adj5 = new TGraphErrors( t_adj5->GetEntries(""), t_adj5->GetV2(), t_adj5->GetV1(), 0, t_adj5->GetV3() );
  g_bshield_adj5->SetLineColor(kBlue);
  g_bshield_adj5->SetMarkerColor(kBlue);
  g_bshield_adj5->SetMarkerStyle(20);
  g_bshield_adj5->SetMarkerSize(1.1);

  t_adj5noCu->Draw("bshield:bext:bshield_err","","");
  TGraphErrors* g_bshield_adj5noCu = new TGraphErrors( t_adj5noCu->GetEntries(""), t_adj5noCu->GetV2(), t_adj5noCu->GetV1(), 0, t_adj5noCu->GetV3() );
  g_bshield_adj5noCu->SetLineColor(kRed);
  g_bshield_adj5noCu->SetMarkerColor(kRed);
  g_bshield_adj5noCu->SetMarkerStyle(20);
  g_bshield_adj5noCu->SetMarkerSize(1.1);



  // -----

  TLegend *leg_c1 = new TLegend(0.5,0.2,0.9,0.4);
  leg_c1->SetNColumns(1);
  leg_c1->AddEntry( g_bshield_sep, "2 layer 'separate'" ,"lp");
  leg_c1->AddEntry( g_bshield_adj, "2 layer 'adjacent'" ,"lp");
  leg_c1->AddEntry( g_bshield_sep4, "4 layer 'separate'" ,"lp");
  leg_c1->AddEntry( g_bshield_adj4, "4 layer 'adjacent'" ,"lp");

  TLegend *leg_c2 = new TLegend(0.5,0.2,0.95,0.3);
  leg_c2->SetNColumns(1);
  leg_c2->AddEntry( g_bshield_adj5, "Cu stabilizer" ,"lp");
  leg_c2->AddEntry( g_bshield_adj5noCu, "w/o Cu stabilizer" ,"lp");

  // -----

  TH1F* htemp_xl = new TH1F("htemp_xl","",501,-0.5,500.5);

  htemp_xl->Reset("ICE");
  t_adj->Draw("bext >> htemp_xl","shielding_factor>0.95");
  float frac_95_adj = htemp_xl->GetBinCenter(htemp_xl->FindLastBinAbove());

  htemp_xl->Reset("ICE");
  t_sep->Draw("bext >> htemp_xl","shielding_factor>0.95");
  float frac_95_sep = htemp_xl->GetBinCenter(htemp_xl->FindLastBinAbove());

  cout << "B95 adj = " << frac_95_adj << " , sep = " << frac_95_sep << endl;


  // -----

  // -----

  TH1F* hframe_2 = new TH1F("hframe_2","",31,-0.5,30.5);
  hframe_2->GetXaxis()->SetTitle("B_{0} [mT]");
  hframe_2->GetYaxis()->SetTitle("B_{shield} [mT]");
  hframe_2->GetYaxis()->SetRangeUser(0,13);

  // -----

  TH1F* hframe_3 = new TH1F("hframe_3","",41,-0.5,40.5);
  hframe_3->GetXaxis()->SetTitle("B_{0} [mT]");
  hframe_3->GetYaxis()->SetTitle("B_{shield} [mT]");
  hframe_3->GetYaxis()->SetRangeUser(0,16);

  // -----

  TLine *l_2 = new TLine(0,0,13,13);
  l_2->SetLineColor(kGray+2);
  l_2->SetLineStyle(2);

  // -----

  TLine *l_3 = new TLine(0,0,16,16);
  l_3->SetLineColor(kGray+2);
  l_3->SetLineStyle(2);

  // -----

  TCanvas *c2 = new TCanvas();
  hframe_2->Draw("");
  leg_c1->Draw();
  g_bshield_sep->Draw("Psame");
  g_bshield_adj->Draw("Psame");
  g_bshield_sep4->Draw("Psame");
  g_bshield_adj4->Draw("Psame");

  l_2->Draw();

  gPad->RedrawAxis();

  c2->Print("plots_report_Dec2014/CritField_results_v6_bshield.png");
  c2->Print("plots_report_Dec2014/CritField_results_v6_bshield.eps");

  // -----

  TCanvas *c3 = new TCanvas();
  hframe_3->Draw("");
  leg_c2->Draw();
  g_bshield_adj5->Draw("Psame");
  g_bshield_adj5noCu->Draw("Psame");

  l_3->Draw();

  gPad->RedrawAxis();

  c3->Print("plots_report_Dec2014/CritField_results_v6_bshield_noCu.png");
  c3->Print("plots_report_Dec2014/CritField_results_v6_bshield_noCu.eps");


}
