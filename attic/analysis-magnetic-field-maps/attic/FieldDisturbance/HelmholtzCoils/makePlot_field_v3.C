/**
 * no SC/FM and SC+FM at liquid Nitrogen temperature
 */
makePlot_field_v3()
{

  vector <string> field_refs;
  field_refs.push_back("10");

  TCanvas *ctemp = new TCanvas();

  TH1F* h_frame_z = new TH1F("h_frame_z","",180,-100,100);
  h_frame_z->GetYaxis()->SetTitle("B_{y} [mT]");
  h_frame_z->GetXaxis()->SetTitle("z - z_{c} [mm]");
  h_frame_z->GetXaxis()->SetTitleOffset(1.5);

  TH1F* h_frame_x = new TH1F("h_frame_x","",180,-100,100);
  h_frame_x->GetYaxis()->SetTitle("B_{y} [mT]");
  h_frame_x->GetXaxis()->SetTitle("x - x_{c} [mm]");
  h_frame_x->GetXaxis()->SetTitleOffset(1.5);

  gStyle->SetOptStat(0);

  for( int i = 0; i < field_refs.size(); i++ )
    {
      string field_ref = field_refs.at(i);

      h_frame_z->GetYaxis()->SetRangeUser(0,15.1);
      h_frame_x->GetYaxis()->SetRangeUser(0,15.1);

      ctemp->cd();

      /* get input trees */
      TTree *t1_warm = new TTree();
      TTree *t2_warm = new TTree();
      TTree *t3_warm = new TTree();

      TTree *t1_sc = new TTree();
      TTree *t2_sc = new TTree();
      TTree *t3_sc = new TTree();

      TTree *t1_fm = new TTree();
      TTree *t2_fm = new TTree();
      TTree *t3_fm = new TTree();

      TTree *t1_cloak = new TTree();
      TTree *t2_cloak = new TTree();
      TTree *t3_cloak = new TTree();

      if ( field_ref == "10" )
        {
          t1_warm->ReadFile("Input_Data/Data_2014_06_20_BvsZ_x128_y98_10mT_warm.txt","");
          t2_warm->ReadFile("Input_Data/Data_2014_06_23_BvsX_y98_z158_10mT_warm.txt","");
          t3_warm->ReadFile("Input_Data/Data_2014_06_23_BvsX_y70_z158_10mT_warm.txt","");

          t1_sc->ReadFile("Input_Data/Data_2014_06_20_BvsZ_x128_y98_10mT.txt","");
          t2_sc->ReadFile("Input_Data/Data_2014_06_20_BvsX_y98_z158_10mT.txt","");
          t3_sc->ReadFile("Input_Data/Data_2014_06_20_BvsX_y70_z158_10mT.txt","");

          //t1_fm->ReadFile("Input_Data/","");
          t2_fm->ReadFile("Input_Data/Data_2014_7_16_BvsX_y98_z158_10mT_SC_FM_warm.csv","");
          t3_fm->ReadFile("Input_Data/Data_2014_7_16_BvsX_y70_z158_10mT_SC_FM_warm.csv","");

          //t1_cloak->ReadFile("Input_Data/Data_2014_7_16_BvsZ_x130_y98_10mT_SC_FM_cryo.csv","");
          //t2_cloak->ReadFile("Input_Data/Data_2014_7_16_BvsX_y98_z158_10mT_SC_FM_Cryo.csv","");
          //t3_cloak->ReadFile("Input_Data/Data_2014_7_16_BvsX_y70_z158_10mT_SC_FM_Cryo.csv","");

	  t1_cloak->ReadFile("Input_Data/Data_2014_07_21_BvsZ_x128_y98_10mT_SC_FM16_cryo.txt","");
          t2_cloak->ReadFile("Input_Data/Data_2014_07_21_BvsX_y98_z158_10mT_SC_FM16_cryo.txt","");
          t3_cloak->ReadFile("Input_Data/Data_2014_07_21_BvsX_y70_z158_10mT_SC_FM16_cryo.txt","");
        }

      /* create graphs */
      t1_warm->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:z-158");
      TGraphErrors* g1_warm = new TGraphErrors( t1_warm->GetEntries(""), t1_warm->GetV2(), t1_warm->GetV1() );
      g1_warm->SetMarkerColor(kRed);
      g1_warm->SetMarkerSize(0.7);

      t2_warm->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:x-128-3");
      TGraphErrors* g2_warm = new TGraphErrors( t2_warm->GetEntries(""), t2_warm->GetV2(), t2_warm->GetV1() );
      g2_warm->SetMarkerColor(kRed);
      g2_warm->SetMarkerSize(0.7);

      t3_warm->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:x-128-3");
      TGraphErrors* g3_warm = new TGraphErrors( t3_warm->GetEntries(""), t3_warm->GetV2(), t3_warm->GetV1() );
      g3_warm->SetMarkerColor(kRed);
      g3_warm->SetMarkerSize(0.7);

      t1_sc->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:z-158");
      TGraphErrors* g1_sc = new TGraphErrors( t1_sc->GetEntries(""), t1_sc->GetV2(), t1_sc->GetV1() );
      g1_sc->SetMarkerColor(kBlue);
      g1_sc->SetMarkerSize(0.7);

      t2_sc->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:x-128-3");
      TGraphErrors* g2_sc = new TGraphErrors( t2_sc->GetEntries(""), t2_sc->GetV2(), t2_sc->GetV1() );
      g2_sc->SetMarkerColor(kBlue);
      g2_sc->SetMarkerSize(0.7);

      t3_sc->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:x-128-3");
      TGraphErrors* g3_sc = new TGraphErrors( t3_sc->GetEntries(""), t3_sc->GetV2(), t3_sc->GetV1() );
      g3_sc->SetMarkerColor(kBlue);
      g3_sc->SetMarkerSize(0.7);

      //t1_fm->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:z-158");
      //TGraphErrors* g1_fm = new TGraphErrors( t1_fm->GetEntries(""), t1_fm->GetV2(), t1_fm->GetV1() );
      //g1_fm->SetMarkerColor(kBlack);
      //g1_fm->SetMarkerSize(0.7);

      t2_fm->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:x-128-3");
      TGraphErrors* g2_fm = new TGraphErrors( t2_fm->GetEntries(""), t2_fm->GetV2(), t2_fm->GetV1() );
      g2_fm->SetMarkerColor(kBlack);
      g2_fm->SetMarkerSize(0.7);

      t3_fm->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:x-128-3");
      TGraphErrors* g3_fm = new TGraphErrors( t3_fm->GetEntries(""), t3_fm->GetV2(), t3_fm->GetV1() );
      g3_fm->SetMarkerColor(kBlack);
      g3_fm->SetMarkerSize(0.7);

      t1_cloak->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:z-158");
      TGraphErrors* g1_cloak = new TGraphErrors( t1_cloak->GetEntries(""), t1_cloak->GetV2(), t1_cloak->GetV1() );
      g1_cloak->SetMarkerColor(kGreen+1);
      g1_cloak->SetMarkerSize(0.7);

      t2_cloak->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:x-128-3");
      TGraphErrors* g2_cloak = new TGraphErrors( t2_cloak->GetEntries(""), t2_cloak->GetV2(), t2_cloak->GetV1() );
      g2_cloak->SetMarkerColor(kGreen+1);
      g2_cloak->SetMarkerSize(0.7);

      t3_cloak->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:x-128-3");
      TGraphErrors* g3_cloak = new TGraphErrors( t3_cloak->GetEntries(""), t3_cloak->GetV2(), t3_cloak->GetV1() );
      g3_cloak->SetMarkerColor(kGreen+1);
      g3_cloak->SetMarkerSize(0.7);

      // -----
      /* Create ratio plots */
      // ... ?


      // -----
      /* lines */
      TLine *lLeft_z  = new TLine(112 - 158, 0, 112 - 158, 15.1);
      TLine *lRight_z = new TLine(202 - 158, 0, 202 - 158, 15.1);

      TLine *lLeft_x  = new TLine(-17.3, 0, -17.3, 15.1);
      TLine *lRight_x = new TLine( 17.3, 0,  17.3, 15.1);

      lLeft_z->SetLineStyle(2);
      lRight_z->SetLineStyle(2);

      lLeft_x->SetLineStyle(2);
      lRight_x->SetLineStyle(2);

      // -----

      /* Update legend */
      TLegend *leg1 = new TLegend(0.65,0.8,0.9,0.9);
      leg1->SetNColumns(2);
      leg1->AddEntry(g1_warm,"reference","p");
      leg1->AddEntry(g1_sc,"SC","p");
      leg1->AddEntry(g1_cloak,"cloak","p");
      //leg1->AddEntry(g1_fm,"FM","p");


      TLegend *leg2 = new TLegend(0.65,0.8,0.9,0.9);
      leg2->SetNColumns(2);
      leg2->AddEntry(g2_warm,"reference","p");
      leg2->AddEntry(g2_sc,"SC","p");
      leg2->AddEntry(g2_cloak,"cloak","p");
      leg2->AddEntry(g2_fm,"FM","p");


      TLegend *leg3 = new TLegend(0.65,0.8,0.9,0.9);
      leg3->SetNColumns(2);
      leg3->AddEntry(g3_warm,"reference","p");
      leg3->AddEntry(g3_sc,"SC","p");
      leg3->AddEntry(g3_cloak,"cloak","p");
      leg3->AddEntry(g3_fm,"FM","p");


      // -----

      TCanvas *c1 = new TCanvas();
      h_frame_z->Draw("rad");
      lLeft_z->Draw("same");
      lRight_z->Draw("same");
      leg1->Draw();
      g1_warm->Draw("LPsame");
      g1_sc->Draw("LPsame");
      //g1_fm->Draw("LPsame");
      g1_cloak->Draw("LPsame");
      gPad->RedrawAxis();

      TCanvas *c2 = new TCanvas();
      h_frame_x->Draw("rad");
      lLeft_x->Draw("same");
      lRight_x->Draw("same");
      leg2->Draw();
      g2_warm->Draw("Psame");
      g2_sc->Draw("Psame");
      g2_fm->Draw("Psame");
      g2_cloak->Draw("Psame");
      gPad->RedrawAxis();

      TCanvas *c3 = new TCanvas();
      h_frame_x->Draw("rad");
      lLeft_x->Draw("same");
      lRight_x->Draw("same");
      leg3->Draw();
      g3_warm->Draw("Psame");
      g3_sc->Draw("Psame");
      g3_fm->Draw("Psame");
      g3_cloak->Draw("Psame");
      gPad->RedrawAxis();

      c1->Print( TString("../Plots/Public/FieldDisturbance_HelmholtzCoils_v3_cloak_").Append(field_ref.c_str()).Append("mT_1.eps") );
      c1->Print( TString("../Plots/Public/FieldDisturbance_HelmholtzCoils_v3_cloak_").Append(field_ref.c_str()).Append("mT_1.png") );

      c2->Print( TString("../Plots/Public/FieldDisturbance_HelmholtzCoils_v3_cloak_").Append(field_ref.c_str()).Append("mT_2.eps") );
      c2->Print( TString("../Plots/Public/FieldDisturbance_HelmholtzCoils_v3_cloak_").Append(field_ref.c_str()).Append("mT_2.png") );

      c3->Print( TString("../Plots/Public/FieldDisturbance_HelmholtzCoils_v3_cloak_").Append(field_ref.c_str()).Append("mT_3.eps") );
      c3->Print( TString("../Plots/Public/FieldDisturbance_HelmholtzCoils_v3_cloak_").Append(field_ref.c_str()).Append("mT_3.png") );

    }
}
