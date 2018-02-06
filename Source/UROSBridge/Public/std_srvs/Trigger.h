#pragma once

#include "ROSBridgeSrv.h"

class UROSBRIDGE_API FROSBridgeSrvStdsrvsTrigger : public FROSBridgeSrv 
{

protected:
    FString Type;

public:
    FROSBridgeSrvStdsrvsTrigger()
    {
        Type = TEXT("srd_srvs/Trigger");
    }

    class Request : public SrvRequest {

    public:
        Request() { }

        virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override {
        }

        static Request GetFromJson(TSharedPtr<FJsonObject> JsonObject)
        {
            Request req; req.FromJson(JsonObject);
            return req;
        }

        virtual FString ToString() const override
        {
            return TEXT("Trigger::Request { } ");
        }

        virtual TSharedPtr<FJsonObject> ToJsonObject() const {
            TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());
            return Object;
        }
    };

    class Response : public SrvResponse {
    private:
        uint8 success;
        FString message;

    public:
        Response() {}
        Response(uint8 success_, FString message_) : success(success_), message(message_) {}
        uint8 GetSuccess() const { return success; }
        FString GetMessage() const { return message; }
        void SetSuccess(uint8 success_) { success = success_; }
        void SetMessage(FString message_) { message = message_; }

        virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override {
            success = JsonObject->GetIntegerField("success");
            message = JsonObject->GetStringField("message");
        }

        static Response GetFromJson(TSharedPtr<FJsonObject> JsonObject)
        {
            Response rep; rep.FromJson(JsonObject);
            return rep;
        }

        virtual FString ToString() const override
        {
            return TEXT("Trigger::Response { success = ") + FString::FromInt(success) + TEXT(", ") +
                TEXT(" message = \"") + message + TEXT("\" } ");
        }

        virtual TSharedPtr<FJsonObject> ToJsonObject() const {
            TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());
            Object->SetNumberField("success", success);
            Object->SetStringField("message", message);
            return Object;
        }
    };

};

/************************************************************************/
/* Namespace version                                                    */
/************************************************************************/
namespace std_srvs
{
	class UROSBRIDGE_API Trigger : public FROSBridgeSrv 
	{

	protected:
		FString Type;

	public:
		Trigger()
		{
			Type = TEXT("srd_srvs/Trigger");
		}

		class Request : public SrvRequest 
		{
		public:
			Request() { }

			virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override 
			{
			}

			static Request GetFromJson(TSharedPtr<FJsonObject> JsonObject)
			{
				Request Req; 
				Req.FromJson(JsonObject);
				return Req;
			}

			virtual FString ToString() const override
			{
				return TEXT("Trigger::Request { } ");
			}

			virtual TSharedPtr<FJsonObject> ToJsonObject() const 
			{
				TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());
				return Object;
			}
		};

		class Response : public SrvResponse 
		{
		private:
			uint8 Success;
			FString Message;

		public:
			Response() {}
			Response(uint8 InSuccess, FString InMessage) : Success(InSuccess), Message(InMessage) {}
			uint8 GetSuccess() const { return Success; }
			FString GetMessage() const { return Message; }
			void SetSuccess(uint8 InSuccess) { Success = InSuccess; }
			void SetMessage(FString InMessage) { Message = InMessage; }

			virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override 
			{
				Success = JsonObject->GetIntegerField("success");
				Message = JsonObject->GetStringField("message");
			}

			static Response GetFromJson(TSharedPtr<FJsonObject> JsonObject)
			{
				Response Resp; Resp.FromJson(JsonObject);
				return Resp;
			}

			virtual FString ToString() const override
			{
				return TEXT("Trigger::Response { success = ") + FString::FromInt(Success) + TEXT(", ") +
					TEXT(" message = \"") + Message + TEXT("\" } ");
			}

			virtual TSharedPtr<FJsonObject> ToJsonObject() const 
			{
				TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());
				Object->SetNumberField("success", Success);
				Object->SetStringField("message", Message);
				return Object;
			}
		};
	};
} // namespace std_srvs