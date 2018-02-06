#pragma once
#include "ROSBridgeMsg.h"

#include "geometry_msgs/Vector3.h"

class FROSBridgeMsgGeometrymsgsInertia : public FROSBridgeMsg
{
    double m; 
    FROSBridgeMsgGeometrymsgsVector3 com;
    double ixx, ixy, ixz, iyy, iyz, izz; 

public:
    FROSBridgeMsgGeometrymsgsInertia()
    {
        MsgType = "geometry_msgs/Inertia";
    }

    FROSBridgeMsgGeometrymsgsInertia
    (double m_, FROSBridgeMsgGeometrymsgsVector3 com_, 
        double ixx_, double ixy_, double ixz_, double iyy_, double iyz_, double izz_) :
        m(m_), com(com_), ixx(ixx_), ixy(ixy_), ixz(ixz_), iyy(iyy_), iyz(iyz_), izz(izz_) 
    {
        MsgType = "geometry_msgs/Inertia";
    }
    
    ~FROSBridgeMsgGeometrymsgsInertia() override {}

    FROSBridgeMsgGeometrymsgsVector3 GetCom() const
    {
        return com; 
    }

    double GetM() const { return m; }
    double GetIxx() const { return ixx; }
    double GetIxy() const { return ixy; }
    double GetIxz() const { return ixz; }
    double GetIyy() const { return iyy; }
    double GetIyz() const { return iyz; }
    double GetIzz() const { return izz; }

    void SetCom(FROSBridgeMsgGeometrymsgsVector3 com_)
    {
        com = com_; 
    }

    void SetM(double m_) { m = m_; }
    void SetIxx(double ixx_) { ixx = ixx_; }
    void SetIxy(double ixy_) { ixy = ixy_; }
    void SetIxz(double ixz_) { ixz = ixz_; }
    void SetIyy(double iyy_) { iyy = iyy_; }
    void SetIyz(double iyz_) { iyz = iyz_; }
    void SetIzz(double izz_) { izz = izz_; }

    virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override {
        m = JsonObject->GetNumberField(TEXT("m")); 
        com = FROSBridgeMsgGeometrymsgsVector3::GetFromJson(JsonObject->GetObjectField(TEXT("com")));
        ixx = JsonObject->GetNumberField(TEXT("ixx"));
        ixy = JsonObject->GetNumberField(TEXT("ixy"));
        ixz = JsonObject->GetNumberField(TEXT("ixz"));
        iyy = JsonObject->GetNumberField(TEXT("iyy"));
        iyz = JsonObject->GetNumberField(TEXT("iyz"));
        izz = JsonObject->GetNumberField(TEXT("izz"));
    }

    static FROSBridgeMsgGeometrymsgsInertia GetFromJson(TSharedPtr<FJsonObject> JsonObject)
    {
        FROSBridgeMsgGeometrymsgsInertia Result;
        Result.FromJson(JsonObject); 
        return Result; 
    }

    virtual FString ToString () const override
    {
        return TEXT("Inertia { m = ") + FString::SanitizeFloat(m) + 
                     TEXT(", com = ") + com.ToString() + 
                     TEXT(", ixx = ") + FString::SanitizeFloat(ixx) + 
                     TEXT(", ixy = ") + FString::SanitizeFloat(ixy) +
                     TEXT(", ixz = ") + FString::SanitizeFloat(ixz) +
                     TEXT(", iyy = ") + FString::SanitizeFloat(iyy) +
                     TEXT(", iyz = ") + FString::SanitizeFloat(iyz) +
                     TEXT(", izz = ") + FString::SanitizeFloat(izz) + TEXT(" } ");
    }

    virtual TSharedPtr<FJsonObject> ToJsonObject() const override {
        TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());
        Object->SetNumberField(TEXT("m"), m); 
        Object->SetObjectField(TEXT("com"), com.ToJsonObject());
        Object->SetNumberField(TEXT("ixx"), ixx);
        Object->SetNumberField(TEXT("ixy"), ixy);
        Object->SetNumberField(TEXT("ixz"), ixz);
        Object->SetNumberField(TEXT("iyy"), iyy);
        Object->SetNumberField(TEXT("iyz"), iyz);
        Object->SetNumberField(TEXT("izz"), izz);
        return Object;
    }

    virtual FString ToYamlString() const override {
        FString OutputString; 
        TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
        FJsonSerializer::Serialize(ToJsonObject().ToSharedRef(), Writer);
        return OutputString;
    }
};

/************************************************************************/
/* Namespace version                                                    */
/************************************************************************/
namespace geometry_msgs
{
	class Inertia : public FROSBridgeMsg
	{
		double M;
		geometry_msgs::Vector3 Com;
		double Ixx, Ixy, Ixz, Iyy, Iyz, Izz;

	public:
		Inertia()
		{
			MsgType = "geometry_msgs/Inertia";
		}

		Inertia
		(double InM, geometry_msgs::Vector3 InCom,
			double InIxx, double InIxy, double InIxz, double InIyy, double InIyz, double InIzz) :
			M(InM), Com(InCom), Ixx(InIxx), Ixy(InIxy), Ixz(InIxz), Iyy(InIyy), Iyz(InIyz), Izz(InIzz)
		{
			MsgType = "geometry_msgs/Inertia";
		}

		~Inertia() override {}

		geometry_msgs::Vector3 GetCom() const
		{
			return Com;
		}

		double GetM() const { return M; }
		double GetIxx() const { return Ixx; }
		double GetIxy() const { return Ixy; }
		double GetIxz() const { return Ixz; }
		double GetIyy() const { return Iyy; }
		double GetIyz() const { return Iyz; }
		double GetIzz() const { return Izz; }

		void SetCom(geometry_msgs::Vector3 InCom)
		{
			Com = InCom;
		}

		void SetM(double InM) { M = InM; }
		void SetIxx(double InIxx) { Ixx = InIxx; }
		void SetIxy(double InIxy) { Ixy = InIxy; }
		void SetIxz(double InIxz) { Ixz = InIxz; }
		void SetIyy(double InIyy) { Iyy = InIyy; }
		void SetIyz(double InIyz) { Iyz = InIyz; }
		void SetIzz(double InIzz) { Izz = InIzz; }

		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override 
		{
			M = JsonObject->GetNumberField(TEXT("m"));
			Com = geometry_msgs::Vector3::GetFromJson(JsonObject->GetObjectField(TEXT("com")));
			Ixx = JsonObject->GetNumberField(TEXT("ixx"));
			Ixy = JsonObject->GetNumberField(TEXT("ixy"));
			Ixz = JsonObject->GetNumberField(TEXT("ixz"));
			Iyy = JsonObject->GetNumberField(TEXT("iyy"));
			Iyz = JsonObject->GetNumberField(TEXT("iyz"));
			Izz = JsonObject->GetNumberField(TEXT("izz"));
		}

		static Inertia GetFromJson(TSharedPtr<FJsonObject> JsonObject)
		{
			Inertia Result;
			Result.FromJson(JsonObject);
			return Result;
		}

		virtual FString ToString() const override
		{
			return TEXT("Inertia { m = ") + FString::SanitizeFloat(M) +
				TEXT(", com = ") + Com.ToString() +
				TEXT(", ixx = ") + FString::SanitizeFloat(Ixx) +
				TEXT(", ixy = ") + FString::SanitizeFloat(Ixy) +
				TEXT(", ixz = ") + FString::SanitizeFloat(Ixz) +
				TEXT(", iyy = ") + FString::SanitizeFloat(Iyy) +
				TEXT(", iyz = ") + FString::SanitizeFloat(Iyz) +
				TEXT(", izz = ") + FString::SanitizeFloat(Izz) + TEXT(" } ");
		}

		virtual TSharedPtr<FJsonObject> ToJsonObject() const override 
		{
			TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());
			Object->SetNumberField(TEXT("m"), M);
			Object->SetObjectField(TEXT("com"), Com.ToJsonObject());
			Object->SetNumberField(TEXT("ixx"), Ixx);
			Object->SetNumberField(TEXT("ixy"), Ixy);
			Object->SetNumberField(TEXT("ixz"), Ixz);
			Object->SetNumberField(TEXT("iyy"), Iyy);
			Object->SetNumberField(TEXT("iyz"), Iyz);
			Object->SetNumberField(TEXT("izz"), Izz);
			return Object;
		}

		virtual FString ToYamlString() const override 
		{
			FString OutputString;
			TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
			FJsonSerializer::Serialize(ToJsonObject().ToSharedRef(), Writer);
			return OutputString;
		}
	};
} // geometry_msgs