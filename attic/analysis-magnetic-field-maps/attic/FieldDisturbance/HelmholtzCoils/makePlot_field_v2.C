/**
 * Use Steel 
 */
makePlot_field_v2()
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
      TTree *t1_no_FM = new TTree();
      TTree *t2_no_FM = new TTree();
      TTree *t3_no_FM = new TTree();

      TTree *t1_w_FM = new TTree();
      TTree *t2_w_FM = new TTree();
      TTree *t3_w_FM = new TTree();

      if ( field_ref == "10" )
        {
          t1_no_FM->ReadFile("Input_Data/Data_2014_06_20_BvsZ_x128_y98_10mT_warm.txt","");
          t2_no_FM->ReadFile("Input_Data/Data_2014_06_23_BvsX_y98_z158_10mT_warm.txt","");
          t3_no_FM->ReadFile("Input_Data/Data_2014_06_23_BvsX_y70_z158_10mT_warm.txt","");

          //t1_w_FM->ReadFile("Input_Data/","");
          t2_w_FM->ReadFile("Input_Data/Data_2014_7_16_BvsX_y98_z158_10mT_SC_FM_warm.csv","");
          t3_w_FM->ReadFile("Input_Data/Data_2014_7_16_BvsX_y70_z158_10mT_SC_FM_warm.csv","");
        }

      /* create graphs */
      t1_no_FM->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:z-158");
      TGraphErrors* g1_no_FM = new TGraphErrors( t1_no_FM->GetEntries(""), t1_no_FM->GetV2(), t1_no_FM->GetV1() );
      g1_no_FM->SetMarkerColor(kRed);

      t2_no_FM->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:x-128-3");
      TGraphErrors* g2_no_FM = new TGraphErrors( t2_no_FM->GetEntries(""), t2_no_FM->GetV2(), t2_no_FM->GetV1() );
      g2_no_FM->SetMarkerColor(kRed);

      t3_no_FM->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:x-128-3");
      TGraphErrors* g3_no_FM = new TGraphErrors( t3_no_FM->GetEntries(""), t3_no_FM->GetV2(), t3_no_FM->GetV1() );
      g3_no_FM->SetMarkerColor(kRed);

      //t1_w_FM->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:z-158");
      //TGraphErrors* g1_w_FM = new TGraphErrors( t1_w_FM->GetEntries(""), t1_w_FM->GetV2(), t1_w_FM->GetV1() );
      //g1_w_FM->SetMarkerColor(kBlack);

      t2_w_FM->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:x-128-3");
      TGraphErrors* g2_w_FM = new TGraphErrors( t2_w_FM->GetEntries(""), t2_w_FM->GetV2(), t2_w_FM->GetV1() );
      g2_w_FM->SetMarkerColor(kBlack);

      t3_w_FM->Draw("B-(B_I0 - B_I0_T0) - B_I0_T0:x-128-3");
      TGraphErrors* g3_w_FM = new TGraphErrors( t3_w_FM->GetEntries(""), t3_w_FM->GetV2(), t3_w_FM->GetV1() );
      g3_w_FM->SetMarkerColor(kBlack);


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
      //TLegend *leg1 = new TLegend(0.75,0.75,0.9,0.9);
      //leg1->SetNColumns(1);
      //leg1->AddEntry(g1_no_FM,"no_FM","p");
      //leg1->AddEntry(g1_w_FM,"w_FM","p");

      TLegend *leg2 = new TLegend(0.75,0.75,0.9,0.9);
      leg2->SetNColumns(1);
      leg2->AddEntry(g2_no_FM,"no_FM","p");
      leg2->AddEntry(g2_w_FM,"w_FM","p");

      TLegend *leg3 = new TLegend(0.75,0.75,0.9,0.9);
      leg3->SetNColumns(1);
      leg3->AddEntry(g3_no_FM,"no_FM","p");
      leg3->AddEntry(g3_w_FM,"w_FM","p");

      // -----

      //TCanvas *c1 = new TCanvas();
      //h_frame_z->Draw("rad");
      //lLeft_z->Draw("same");
      //lRight_z->Draw("same");
      //leg1->Draw();
      //g1_no_FM->Draw("LPsame");
      //g1_w_FM->Draw("LPsame");
      //gPad->RedrawAxis();

      TCanvas *c2 = new TCanvas();
      h_frame_x->Draw("rad");
      lLeft_x->Draw("same");
      lRight_x->Draw("same");
      leg2->Draw();
      g2_no_FM->Draw("Psame");
      g2_w_FM->Draw("Psame");
      gPad->RedrawAxis();

      TCanvas *c3 = new TCanvas();
      h_frame_x->Draw("rad");
      lLeft_x->Draw("same");
      lRight_x->Draw("same");
      leg3->Draw();
      g3_no_FM->Draw("Psame");
      g3_w_FM->Draw("Psame");
      gPad->RedrawAxis();

      c1->Print( TString("../Plots/Public/FieldDisturbance_HelmholtzCoils_v2_no_FM_w_FM_").Append(field_ref.c_str()).Append("mT_1.eps") );
      c1->Print( TString("../Plots/Public/FieldDisturbance_HelmholtzCoils_v2_no_FM_w_FM_").Append(field_ref.c_str()).Append("mT_1.png") );

      c2->Print( TString("../Plots/Public/FieldDisturbance_HelmholtzCoils_v2_no_FM_w_FM_").Append(field_ref.c_str()).Append("mT_2.eps") );
      c2->Print( TString("../Plots/Public/FieldDisturbance_HelmholtzCoils_v2_no_FM_w_FM_").Append(field_ref.c_str()).Append("mT_2.png") );

      c3->Print( TString("../Plots/Public/FieldDisturbance_HelmholtzCoils_v2_no_FM_w_FM_").Append(field_ref.c_str()).Append("mT_3.eps") );
      c3->Print( TString("../Plots/Public/FieldDisturbance_HelmholtzCoils_v2_no_FM_w_FM_").Append(field_ref.c_str()).Append("mT_3.png") );

    }
}
